import unreal
import os, sys, argparse
import time

default_resolution = [1920, 1080]

parser = argparse.ArgumentParser(description='Render movie from an Unreal Level Sequence.')
parser.add_argument('seq_names', type=str, nargs='+',
					help="A level sequnce full path to render a movie from "
						" like /Game/Cinematics/sc10sc_03_0003.sc10sc_03_0003 ")
parser.add_argument('-res_x', type=float, default=default_resolution[0],
					help='x for output resolution (x,y)')
parser.add_argument('-res_y', type=float, default=default_resolution[1],
					help='y for output resolution (x,y)')
parser.add_argument('-use_burn_in', type=int, default=0,
					help='Use Burn In or not')
parser.add_argument('-encorder_format', type=str, default="422",
					help='AppleProResEncoderFormat : "422 HQ", "422", "422 LT", "422 Proxy", "4444", "4444 XQ"')
parser.add_argument('-warm_up_frame_count', type=int, default=0,
					help='Warm Up Frame Count')
parser.add_argument('-delay_before_warm_up', type=float, default=0.0,
					help='Delay Before Warm Up')
parser.add_argument('-delay_before_shot_warm_up', type=float, default=0.0,
					help='Delay Before Shot Warm Up')
parser.add_argument('-delay_every_frame', type=float, default=0.0,
					help='Delay Every Time')
parser.add_argument('-game_mode_override', type=str, default="None",
					help='Game Mode Override in World Settings')
parser.add_argument('-project_name', type=str, default="Default",
					help='Project Name for render')
parser.add_argument('-artist_name', type=str, default="Default",
					help='Artist Name')
parser.add_argument('-use_audio_capture', type=int, default=0,
					help='Use the audio capture feature')
parser.add_argument('--use_current_level', action='store_true',
					help='Use the current level and do not open or load an another level')


#parser.print_help()
args = parser.parse_args()
unreal.log(args)

# Get sequence name from Arguments
seq_names = args.seq_names
proj_names = args.project_name
artist_names = args.artist_name

def on_render_movie_finished(success):
	print("# Movie has finished rendering. Python can now invoke another movie render if needed. Sucess: " + str(success))
	if len(seq_names)>0:
		print("# Sequcnes in a queue =", seq_names)
		render_movies()
	else:
		print("# All sequences in a quene have been rendered!!!! Done!!!!")

on_finished_callback = unreal.OnRenderMovieStopped()
on_finished_callback.bind_callable(on_render_movie_finished)

def render_sequence_to_movie(sequencer_asset_path, level_name, level_path, output_file_name, resolution=(1280,720), 
							game_mode_override='None',
							warm_up_frame_count=0,
							delay_before_warm_up=0.0,
							delay_before_shot_warm_up=0.0,
							delay_every_frame=0.0,
							use_burn_in=False, encorder_format='422'):
	# 1) Create an instance of our UAutomatedLevelSequenceCapture and override all of the settings on it. This class is currently
	# set as a config class so settings will leak between the Unreal Sequencer Render-to-Movie UI and this object. To work around
	# this, we set every setting via the script so that no changes the user has made via the UI will affect the script version.
	# The users UI settings will be reset as an unfortunate side effect of this.
	capture_settings = unreal.AutomatedLevelSequenceCapture()

	# Set all POD settings on the UMovieSceneCapture
	output_dir = unreal.SystemLibrary.get_project_directory() + "Saved/VideoCaptures/"
	capture_settings.settings.output_directory = unreal.DirectoryPath(output_dir)
	if not os.path.exists(output_dir):
		os.mkdir(output_dir)

	#capture_settings.settings.movie_extension = '.avi'



	# If you game mode is implemented in Blueprint, load_asset(...) is going to return you the C++ type ('Blueprint') and not what the BP says it inherits from.
	# Instead, because game_mode_override is a TSubclassOf<AGameModeBase> we can use unreal.load_class to get the UClass which is implicitly convertable.
	# ie: capture_settings.settings.game_mode_override = unreal.load_class(None, "/Game/AI/TestingSupport/AITestingGameMode.AITestingGameMode_C")

	editor_world_settings = unreal.EditorLevelLibrary.get_editor_world().get_world_settings()

	''' game_mode_override is not working
		so change game_mode in world setting temporatily '''
	print "# World Setting - Game Mode Input = " + game_mode_override
	print "# World Setting - Game Mode = " + str(editor_world_settings.default_game_mode) + " - type = " + str(type(editor_world_settings.default_game_mode))
	if game_mode_override=='None':
		unreal.EditorLevelLibrary.get_editor_world().get_world_settings().set_editor_property('default_game_mode', None)
	elif game_mode_override=='BP_CameraGameMode':
		unreal.EditorLevelLibrary.get_editor_world().get_world_settings().set_editor_property('default_game_mode', unreal.load_class(None,'/VirtualCamera/Custom/BP_CameraGameMode.BP_CameraGameMode_C'))
	else:
		pass

	print "# World Setting - Game Mode Override = " + str(editor_world_settings.default_game_mode) + " - type = " + str(type(editor_world_settings.default_game_mode))
	

	capture_settings.settings.game_mode_override = None
	#if game_mode_override=='BP_CameraGameMode':
	#	capture_settings.settings.game_mode_override = None
	capture_settings.settings.output_format = output_file_name
	capture_settings.settings.overwrite_existing = False
	capture_settings.settings.use_relative_frame_numbers = False
	capture_settings.settings.handle_frames = 0
	capture_settings.settings.zero_pad_frame_numbers = 4
	# If you wish to override the output framerate you can use these two lines, otherwise the framerate will be derived from the sequence being rendered
	capture_settings.settings.use_custom_frame_rate = True
	capture_settings.settings.custom_frame_rate = unreal.FrameRate(24,1)
	capture_settings.settings.resolution.res_x = resolution[0]
	capture_settings.settings.resolution.res_y = resolution[1]
	capture_settings.settings.enable_texture_streaming = False
	capture_settings.settings.cinematic_engine_scalability = True
	capture_settings.settings.cinematic_mode = True
	capture_settings.settings.allow_movement = False 	# Requires cinematic_mode = True
	capture_settings.settings.allow_turning = False 	# Requires cinematic_mode = True
	capture_settings.settings.show_player = False 		# Requires cinematic_mode = True
	capture_settings.settings.show_hud = False 			# Requires cinematic_mode = True
	capture_settings.use_separate_process = False
	capture_settings.close_editor_when_capture_starts = False 					# Requires use_separate_process = True
	capture_settings.additional_command_line_arguments = "-NOSCREENMESSAGES"	# Requires use_separate_process = True
	capture_settings.inherited_command_line_arguments = ""						# Requires use_separate_process = True

	# Set all the POD settings on UAutomatedLevelSequenceCapture
	capture_settings.use_custom_start_frame = False 	# If False, the system will automatically calculate the start based on sequence content
	capture_settings.use_custom_end_frame = False 		# If False, the system will automatically calculate the end based on sequence content
	capture_settings.custom_start_frame = unreal.FrameNumber(0)		# Requires use_custom_start_frame = True
	capture_settings.custom_end_frame = unreal.FrameNumber(0)		# Requires use_custom_end_frame = True
	capture_settings.warm_up_frame_count = warm_up_frame_count
	capture_settings.delay_before_warm_up = delay_before_warm_up
	capture_settings.delay_before_shot_warm_up = delay_before_shot_warm_up
	capture_settings.delay_every_frame = delay_every_frame

	capture_settings.write_edit_decision_list = True

	# Tell the capture settings which level sequence to render with these settings. The asset does not need to be loaded, 
	# as we're only capturing the path to it and when the PIE instance is created it will load the specified asset.
	# If you only had a reference to the level sequence, you could use "unreal.SoftObjectPath(mysequence.get_path_name())"
	capture_settings.level_sequence_asset = unreal.SoftObjectPath(sequencer_asset_path)

	# To configure the video output we need to tell the capture settings which capture protocol to use. The various supported
	# capture protocols can be found by setting the Unreal Content Browser to "Engine C++ Classes" and filtering for "Protocol"
	# ie: CompositionGraphCaptureProtocol, ImageSequenceProtocol_PNG, etc. Do note that some of the listed protocols are not intended
	# to be used directly. 
	# Right click on a Protocol and use "Copy Reference" and then remove the extra formatting around it. ie: 
	# Class'/Script/MovieSceneCapture.ImageSequenceProtocol_PNG' gets transformed into "/Script/MovieSceneCapture.ImageSequenceProtocol_PNG"
	
	#capture_settings.set_image_capture_protocol_type(unreal.load_class(None, "/Script/MovieSceneCapture.VideoCaptureProtocol"))
	capture_settings.set_image_capture_protocol_type(unreal.load_class(None, "/Script/AppleProResMedia.AppleProResEncoderProtocol"))
	# After we have set the capture protocol to a soft class path we can start editing the settings for the instance of the protocol that is internallyc reated.
	#capture_settings.get_image_capture_protocol().compression_quality = 100
		
	# The other complex settings is the burn-in. Create an instance of the LevelSequenceBurnInOptions which is used to 
	# specify if we should use a burn in, and then which settings.
	burn_in_options = unreal.LevelSequenceBurnInOptions()
	#unreal.log('use_burn_in =' + str(use_burn_in))
	burn_in_options.use_burn_in = use_burn_in
	#unreal.log('burn_in_options.use_burn_in =' + str(burn_in_options.use_burn_in))
		

	# You have to specify a path to a class to use for the burn in (if use_burn_in = True), and this class specifies a UClass to define the
	# settings object type. We've created a convinence function which takes the class path, loads the class at that path and assigns it to 
	# the Settings object.
	#burn_in_options.set_burn_in(unreal.SoftClassPath("/Engine/Sequencer/DefaultBurnIn.DefaultBurnIn_C"))
	burn_in_options.set_burn_in(unreal.SoftClassPath("/MofacRenderMovie/CustomBurnIn.CustomBurnIn_C"))	
	
	# The default burn in is implemented entirely in Blueprint which means that the method we've been using to set properties will not 
	# work for it. The python bindings that turn bSomeVariableName into "some_variable_name" only work for C++ classes with 
	# UPROPERTY(BlueprintReadWrite) marked fields. Python doesn't know about the existence of Blueprint classes and their fields, so we 
	# have to use an alternative method.
	burn_in_options.settings.set_editor_property('TopLeftText', "{FocalLength}mm,{Aperture},{FocusDistance}")
	burn_in_options.settings.set_editor_property('TopCenterText', "{MasterName} - {Date} - {EngineVersion} - " + proj_names)
	burn_in_options.settings.set_editor_property('TopRightText', artist_names)

	burn_in_options.settings.set_editor_property('BottomLeftText', "Level: " + level_name + "\nPath: " + level_path + "\n{ShotName}")
	burn_in_options.settings.set_editor_property('BottomCenterText', "{hh}:{mm}:{ss}:{ff} ({MasterFrame})")
	burn_in_options.settings.set_editor_property('BottomRightText', "{shh}:{smm}:{sss}:{sff} {SourceTimecode} {ShotFrame}")

	# Load a Texture2D asset and assign it to the UTexture2D reference that Watermark is.
	# burn_in_settings.set_editor_property('Watermark', None)
	# Note that this example creates a really obvious watermark (a big blurry green smiley face) just so that you know it's working!
	#burn_in_options.settings.set_editor_property('Watermark', unreal.load_asset("/Engine/EngineResources/AICON-Green"))
	#burn_in_options.settings.set_editor_property('WatermarkTint', unreal.LinearColor(1.0, 0.5, 0.5, 0.5)) # Create a FLinearColor to tint our Watermark


	# Assign our created instances to our original capture_settings object.
	capture_settings.burn_in_options = burn_in_options

	# Finally invoke Sequencer's Render to Movie functionality. This will examine the specified settings object and either construct a new PIE instance to render in,
	# or create and launch a new process (optionally shutting down your editor).

	#unreal.log(capture_settings.get_image_capture_protocol().get_editor_property('EncodingFormat'))
	'''
	enum class EAppleProResEncoderFormats : uint8
	{
		F_422HQ UMETA(DisplayName = "422 HQ"),
		F_422 UMETA(DisplayName = "422"),
		F_422LT UMETA(DisplayName = "422 LT"),
		F_422Proxy UMETA(DisplayName = "422 Proxy"),
		F_4444 UMETA(DisplayName = "4444"),
		F_4444XQ UMETA(DisplayName = "4444 XQ"),
	};
	'''
	TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_422
	#print type(TargetEncoderFormat)
	#print TargetEncoderFormat
	#print dir(type(TargetEncoderFormat))
	if encorder_format == '422 HQ':
		TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_422HQ
	elif encorder_format == '422':
		pass
	elif encorder_format == '422 LT':
		TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_422LT
	elif encorder_format == '422 Proxy':
		TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_422_PROXY
	elif encorder_format == '4444':
		TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_4444
	elif encorder_format == '4444 XQ':
		TargetEncoderFormat = unreal.AppleProResEncoderFormats.F_4444XQ
	
	capture_settings.get_image_capture_protocol().set_editor_property('EncodingFormat', TargetEncoderFormat)

	if args.use_audio_capture:
		capture_settings.set_audio_capture_protocol_type(unreal.load_class(None, "/Script/MovieSceneCapture.MasterAudioSubmixCaptureProtocol"))
		capture_settings.get_audio_capture_protocol().set_editor_property('FileName', output_file_name)
	#unreal.log(capture_settings.get_image_capture_protocol().get_editor_property('EncodingFormat'))
	#unreal.log(type(capture_settings.get_image_capture_protocol().get_editor_property('EncodingFormat')))
	
	unreal.SequencerTools.render_movie(capture_settings, on_finished_callback)

def render_movies():
	seq_name = seq_names.pop(0)
	unreal.log("#----" + seq_name + "----#")

	# Asset Registry
	assetRegistry = unreal.AssetRegistryHelpers.get_asset_registry()
	# asset data
	assetData = assetRegistry.get_asset_by_object_path(seq_name)
	package_name = assetData.package_name
	output_file_name = str(package_name).split('/')[-1]
	level_name =""
	level_path =""

	if not args.use_current_level:
		unreal.EditorLoadingAndSavingUtils.new_blank_map(False)
		dependency_options= unreal.AssetRegistryDependencyOptions(
									include_soft_package_references=True, 
									include_hard_package_references=False)
		dependencies = assetRegistry.get_dependencies(package_name, dependency_options)

		world_to_load = None
		if dependencies is not None:
			for d in dependencies:
				unreal.log(d)
				d_path = str(d) + '.' + str(d).split('/')[-1]
				print d_path
				d_asset_data = assetRegistry.get_asset_by_object_path(d_path)
				if d_asset_data.asset_class == 'World':
					world_to_load = d_path
					print "Let's load a WORLD!!!!!"
					unreal.EditorLoadingAndSavingUtils.load_map(d_path)
					break
				else:
					print d_path+': is not a World!!!'
		if world_to_load is None:
			assert("No World to load!!!!!!")
			
		level_name = str(d_path).split('.')[-1]
		level_path = str(d_path).rsplit('/', 1)[-2]
	
	else:
		dependency_options= unreal.AssetRegistryDependencyOptions(
									include_soft_package_references=True, 
									include_hard_package_references=False)
		dependencies = assetRegistry.get_dependencies(package_name, dependency_options)
		
		world_to_load = None
		if dependencies is not None:
			for d in dependencies:
					unreal.log(d)
					d_path = str(d) + '.' + str(d).split('/')[-1]
					print d_path
					d_asset_data = assetRegistry.get_asset_by_object_path(d_path)
					if d_asset_data.asset_class == 'World':
						world_to_load = d_path
						break;
						
		level_name = str(d_path).split('.')[-1]
		level_path = str(d_path).rsplit('/', 1)[-2]
		
	#unreal.log(output_file_name)
	#unreal.log('before use_burn_in =' + str(args.use_burn_in))
	render_sequence_to_movie(seq_name, level_name, level_path, output_file_name, 
							resolution=(args.res_x, args.res_y),
							encorder_format=args.encorder_format,
							game_mode_override=args.game_mode_override,
							warm_up_frame_count=args.warm_up_frame_count,
							delay_before_warm_up=args.delay_before_warm_up,
							delay_before_shot_warm_up=args.delay_before_shot_warm_up,
							delay_every_frame= args.delay_every_frame,
							use_burn_in=args.use_burn_in)



render_movies()



# load Empty level to reset the World in Editor

'''
unreal.log("# Open New Level -> World'/Game/BLUEPRINT/EmptyLevel.EmptyLevel'")
unreal.EditorLevelLibrary.load_level("World'/Game/BLUEPRINT/EmptyLevel.EmptyLevel'")
'''


'''


capture_settings = unreal.AutomatedLevelSequenceCapture()
unreal.log(capture_settings.settings.movie_extension)
capture_settings.settings.set_editor_property('movie_extension', '.mov')
unreal.log(capture_settings.settings.movie_extension)
capture_settings.level_sequence_asset = unreal.SoftObjectPath(seq_name)

lvSeq = unreal.EditorAssetLibrary.load_asset(seq_name)
bindings = lvSeq.get_bindings()
display_rate = lvSeq.get_display_rate()
playback_start = lvSeq.get_playback_start()
playback_end = lvSeq.get_playback_end()


unreal.log('# dispaly_rate = {}/{}'.format(display_rate.numerator, display_rate.denominator))
unreal.log('# playback start, end = ({}, {})'.format(playback_start, playback_end))

# spawn level sequcen actor
lvSeqActor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.LevelSequenceActor, [0,0,0])
lvSeqActor.set_sequence(lvSeq)
lvSeqPlayer = lvSeqActor.sequence_player

# sequence at start frame
unreal.log(lvSeqActor.get_sequence().get_playback_start())
lvSeqPlayer.scrub_to_frame(unreal.FrameTime(unreal.FrameNumber(lvSeqActor.get_sequence().get_playback_start())))

unreal.log(bindings)
for binding in bindings:
	unreal.log(binding)



# Invoke Sequencer's Render to Movie. This will throw an exception if a movie render is already
# in progress, an invalid setting is passed, etc.
try:
	print("Rendering to movie...")
	unreal.log(capture_settings.settings.movie_extension)
	asdfkaljl
	unreal.SequencerTools.render_movie(capture_settings, unreal.OnRenderMovieStopped())
except Exception as e:
	print("Python Caught Exception:")
	print(e)

'''
'''
lvSeq = unreal.EditorAssetLibrary.load_asset(seq_name)
bindings = lvSeq.get_bindings()
display_rate = lvSeq.get_display_rate()
playback_start = lvSeq.get_playback_start()
playback_end = lvSeq.get_playback_end()

unreal.log('# dispaly_rate = {}/{}'.format(display_rate.numerator, display_rate.denominator))
unreal.log('# playback start, end = ({}, {})'.format(playback_start, playback_end))

# spawn level sequcen actor
#lvSeqActor = unreal.EditorLevelLibrary.spawn_actor_from_class(unreal.LevelSequenceActor, [0,0,0])
#lvSeqActor.set_sequence(lvSeq)
#lvSeqPlayer = lvSeqActor.sequence_player

# sequence at start frame
#unreal.log(lvSeqActor.get_sequence().get_playback_start())
#lvSeqPlayer.scrub_to_frame(unreal.FrameTime(unreal.FrameNumber(lvSeqActor.get_sequence().get_playback_start())))

# capture settings
movieSceneCaptureSettings = unreal.MovieSceneCaptureSettings()
#movieSceneCaptureSettings.set_editor_property("movie_extension", '.mov')
movieSceneCaptureSettings.set_editor_property("show_player", False)

unreal.log(movieSceneCaptureSettings.output_directory)
unreal.log(movieSceneCaptureSettings.movie_extension)
unreal.log(movieSceneCaptureSettings.frame_rate)
unreal.log(movieSceneCaptureSettings.cinematic_mode)
unreal.log(movieSceneCaptureSettings.show_player)


moveSceneCapture = unreal.MovieSceneCapture()
moveSceneCapture.set_editor_property("settings", movieSceneCaptureSettings)
onRenderMovieStopped = unreal.OnRenderMovieStopped()
unreal.SequencerTools.render_movie(moveSceneCapture, onRenderMovieStopped)
'''