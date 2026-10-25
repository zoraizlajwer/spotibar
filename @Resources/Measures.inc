;			PLUGINS AND SETTINGS

;SPOTIFY PLAYER

[MeasurePlayerSpotify]
Measure=NowPlaying
PlayerName=Spotify
PlayerType=TITLE

;WEBNOWPLAYING PLAYER

[MeasureWebNowPlaying]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Status

[MeasureTitle1]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
IfMatch=^$
IfMatchAction=[!ShowMeter LaunchSpotifyImage][!ShowMeter MeterLaunchSpotifyFunction][!HideMeterGroup AfterSpotifyMeters][!HideMeterGroup ControlPanel][!UpdateMeter *][!Redraw]
IfNotMatchAction=[!HideMeter LaunchSpotifyImage][!HideMeter MeterLaunchSpotifyFunction][!ShowMeterGroup AfterSpotifyMeters][!UpdateMeter *][!Redraw]

[MeasureTitle2]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
IfMatch=^$
IfMatchAction=[!ShowMeter LaunchSpotifyImage][!ShowMeter MeterLaunchSpotifyFunction][!HideMeterGroup HoverShowMeters][!HideMeterGroup ActivatedMeters][!UpdateMeter *][!Redraw]
IfNotMatchAction=[!HideMeter LaunchSpotifyImage][!HideMeter MeterLaunchSpotifyFunction][!ShowMeterGroup HoverShowMeters][!UpdateMeter *][!Redraw]

[MeasureArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist

[MeasurePlayPause]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
Substitute="0":"play","1":"pause","2":"play"
IfCondition=1
IfTrueAction=[!SetOption MeterPlayPause ImageName "#@#Images\#IconFolder#\[*MeasurePlayPause*].png"][!UpdateMeter MeterPlayPause]

[MeasureRepeat]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Repeat
IfCondition=MeasureRepeat = 0
IfTrueAction=[!SetOption MeterRepeat ImageName "#@#Images\#IconFolder#\repeat.png"][!UpdateMeter MeterRepeat][!Redraw]
IfCondition2=MeasureRepeat = 1
IfTrueAction2=[!SetOption MeterRepeat ImageName "#@#Images\Highlight\repeatonce.png"][!UpdateMeter MeterRepeat][!Redraw]
IfCondition3=MeasureRepeat = 2
IfTrueAction3=[!SetOption MeterRepeat ImageName "#@#Images\Highlight\repeat.png"][!UpdateMeter MeterRepeat][!Redraw]

[MeasureCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
CoverPath=#@#Cover.png

[MeasureCoverProgressBar]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
OnChangeAction=[!UpdateMeter ProgressBar][!Redraw]

;			SOUND

[MeasureWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin

;           VISUALIZER

[MeasureAudioOutput]
Measure=Plugin
Plugin=AudioLevel
Port=Output
FFTSize=2048
FFTOverlap=1024
FFTAttack=60
FFTDecay=80
FreqMin=30
FreqMax=10000
Sensitivity=16
Bands=#Bars#

[MeasureAudio1]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=1
AverageSize=4

[MeasureAudio2]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=2
AverageSize=4

[MeasureAudio3]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=3
AverageSize=4

[MeasureAudio4]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=4
AverageSize=4

[MeasureAudio5]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=5
AverageSize=4

[MeasureAudio6]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=6
AverageSize=4

[MeasureAudio7]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=7
AverageSize=4

[MeasureAudio8]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=8
AverageSize=4

[MeasureAudio9]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioOutput
Type=Band
BandIdx=9
AverageSize=4

