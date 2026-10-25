;			Spotify Launch Button

[MeterLaunchSpotifyFunction]
Meter=Shape
Shape=Rectangle 0,0,#ContainerWH#,#ContainerWH#,#Radius# | StrokeWidth 0 | Fill Color #BoxBGColor1#
X = #LeftIndent#
Y = #TopIndent#
AntiAlias = 1
LeftMouseUpAction=!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"

[LaunchSpotifyImage]
Meter=Image
ImageName=#@#Images\#IconFolder#\Spotify.png
X = 6r
Y = 5r
W=([MeterLaunchSpotifyFunction:W]-10)
H=([MeterLaunchSpotifyFunction:H]-10)
LeftMouseUpAction=[!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"]
MouseScrollUpAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"]
MouseScrollDownAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"]
MouseOverAction=[!SetOption LaunchSpotifyImage ImageName "#@#Images\Highlight\Spotify.png"][!UpdateMeter LaunchSpotifyImage][!Redraw]
MouseLeaveAction=[!SetOption LaunchSpotifyImage ImageName "#@#Images\#IconFolder#\Spotify.png"][!UpdateMeter LaunchSpotifyImage][!Redraw]
PreserveAspectRatio=1
DynamicVariables=1

;			Others

[Indent]
Meter=Image
SolidColor=0,0,0,0
X=#LeftIndent#
Y=(#TopIndent#+4)
H=[MeterLaunchSpotifyFunction:H]
W = [MeterLaunchSpotifyFunction:W]

[HoveringFunction]
Meter = Shape
Group = ActivatedMeters
X = #LeftIndent#
Shape = Rectangle 0,0,#ContainerExpandWidth#,#SkinH#,#Radius#| Fill Color 0,0,0,1 | StrokeWidth 0 | StrokeColor #FillColorL#
MouseLeaveAction=[!Delay 0][!HideMeterGroup ActivatedMeters][!HideMeter HoveringFunction]
MouseOverAction=[!ShowMeterGroup ActivatedMeters][!UpdateMeter *][!Redraw]
Hidden = 1

;			Playing Container

[MeterPlayingControlsContainer]
Meter=Shape
Group=ActivatedMeters
X=0r
Y=#TopIndent#
Shape=Rectangle 0,0,#ContainerExpandWidth#,#ContainerWH#,#Radius# |Fill Color #BoxBGColor1# | StrokeWidth 0 | StrokeColor #FillColorL#
RightMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"]
MouseScrollUpAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"]
MouseScrollDownAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"]
Hidden = 1
DynamicVariables=1

[MeterPlayingContainer]
Meter=Shape
Group=HoverShowMeters
X=0r
Y=#TopIndent#
Shape=Rectangle 0,0,#ContainerWH#,#ContainerWH#,#Radius# |  Fill Color #BoxBGColor2#  | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=[!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"]
RightMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"]
MouseScrollUpAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"]
MouseScrollDownAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"]
MouseOverAction=[!ShowMeter HoveringFunction][!ShowMeterGroup ActivatedMeters][!UpdateMeter *][!Redraw]
DynamicVariables = 1

;			PROGRESS BAR COVER

[ProgressBarContainer]
Meter=Shape
Shape=Rectangle 0,0,#ContainerWH#,#ContainerWH#,#Radius# | StrokeWidth 0 |Fill Color #BoxBGColor1#
Group=HoverShowMeters
X=0r
Y=(#TopIndent#)
DynamicVariables=1

[ProgressBar]
Meter=Roundline
Group=HoverShowMeters
MeasureName=MeasureCoverProgressBar
StartAngle=(1.5*PI)
RotationAngle=(2*PI)
LineStart=0
LineLength=(Sqrt((#ContainerWH#)**2+(#ContainerWH#)**2)/2)
LineColor=#AccentColor#
Solid=1
AntiAlias=1
W=(#ContainerWH#)
H=(#ContainerWH#)
DynamicVariables=1
Container=ProgressBarContainer

;			COVER PICTURE

[CoverContainer]
Meter=Shape
Shape=Rectangle 0, 0, #CoverSize#, #CoverSize#, (#Radius#-0.8)
Group=HoverShowMeters
X = ((#ContainerWH#-#CoverSize#)/2) + #LeftIndent#
Y = (((#ContainerWH#-#CoverSize#)/2)+#TopIndent#)
DynamicVariables=1
AntiAlias=1
Hidden = 1

[Cover]
Meter=Image
Group=HoverShowMeters
MeasureName=MeasureCover
PreserveAspectRatio=2
W=#CoverSize#
H=#CoverSize#
DynamicVariables=1
Container=CoverContainer
RightMouseUpAction=[!CommandMeasure "MeasureWin7Audio" "ToggleMute"]
MouseScrollUpAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"]
MouseScrollDownAction=[!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"]
OnChangeAction=[!UpdateMeasure "Chameleon"][!UpdateMeter *][!Redraw]
Hidden = 1

;			PREVIOUS TRACK BUTTON

[MeterPreviousFunction]
Meter=Shape
Group=ActivatedMeters
X=11R
Y=(#TopIndent#-1)
Shape=Rectangle -1,11,(#ButtonWHothers#+2),(#ButtonWHothers#+2) | Fill Color 0,0,0,1 | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=!CommandMeasure "MeasureWebNowPlaying" "Previous"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1
AntiAlias = 1

[MeterPrevious]
Meter=Image
ImageName=#@#Images\#IconFolder#\skipback.png
Group=ActivatedMeters
X=[MeterPreviousFunction:X]
Y=(#TopIndent#+11)
W=#ButtonWHothers#
H=#ButtonWHothers#
LeftMouseUpAction=!CommandMeasure "MeasureWebNowPlaying" "Previous"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseOverAction=[!SetOption MeterPrevious ImageName "#@#Images\Highlight\skipback.png"][!UpdateMeter MeterPrevious][!Redraw]
MouseLeaveAction=[!SetOption MeterPrevious ImageName "#@#Images\#IconFolder#\skipback.png"][!UpdateMeter MeterPrevious][!Redraw]
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1

;			PLAY/PAUSE BUTTON

[MeterPlayPauseFunction]
Meter=Shape
Group=ActivatedMeters
X=4R
Y=[MeterPreviousFunction:Y]
Shape=Rectangle -1,8,(#ButtonWHplay#+2),(#ButtonWHplay#+2) | Fill Color 0,0,0,1 | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=!CommandMeasure "MeasurePlayPause" "PlayPause"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1
AntiAlias = 1

[MeterPlayPause]
Meter=Image
ImageName=#@#Images\#IconFolder#\[MeasurePlayPause].png
Group=ActivatedMeters
X=([MeterPlayPauseFunction:X])
Y=9r
W=#ButtonWHplay#
H=#ButtonWHplay#
DynamicVariables=1
LeftMouseUpAction=!CommandMeasure "MeasurePlayPause" "PlayPause"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseOverAction=[!SetOption MeterPlayPause ImageName "#@#Images\Highlight\[*MeasurePlayPause*].png"][!UpdateMeter MeterPlayPause][!Redraw]
MouseLeaveAction=[!SetOption MeterPlayPause ImageName "#@#Images\#IconFolder#\[*MeasurePlayPause*].png"][!UpdateMeter MeterPlayPause][!Redraw]
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1

;			NEXT TRACK BUTTON

[MeterNextFunction]
Meter=Shape
Group=ActivatedMeters
X=4R
Y=[MeterPreviousFunction:Y]
Shape=Rectangle -1,11,(#ButtonWHothers#+2),(#ButtonWHothers#+2) | Fill Color 0,0,0,1 | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=!CommandMeasure "MeasureWebNowPlaying" "Next"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1
AntiAlias = 1

[MeterNext]
Meter=Image
ImageName=#@#Images\#IconFolder#\skipnext.png
Group=ActivatedMeters
X=([MeterNextFunction:X])
Y=[MeterPrevious:Y]
W=#ButtonWHothers#
H=#ButtonWHothers#
LeftMouseUpAction=!CommandMeasure "MeasureWebNowPlaying" "Next"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseOverAction=[!SetOption MeterNext ImageName "#@#Images\Highlight\skipnext.png"][!UpdateMeter MeterNext][!Redraw]
MouseLeaveAction=[!SetOption MeterNext ImageName "#@#Images\#IconFolder#\skipnext.png"][!UpdateMeter MeterNext][!Redraw]
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1

;			Repeat Button

[MeterRepeatFunction]
Meter=Shape
Group=ActivatedMeters
X=6R
Y=[MeterPreviousFunction:Y]
Shape=Rectangle -1,11,(#ButtonWHothers#+2),(#ButtonWHothers#+2) | Fill Color 0,0,0,1 | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=!CommandMeasure "MeasureRepeat" "Repeat"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1
AntiAlias = 1

[MeterRepeat]
Meter=Image
Group=ActivatedMeters
X=([MeterRepeatFunction:X]-1)
Y=([MeterPrevious:Y]-(3/2))
W=(#ButtonWHothers#+3)
H=(#ButtonWHothers#+3)
DynamicVariables=1
Hidden=1
LeftMouseUpAction=!CommandMeasure "MeasureRepeat" "Repeat"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"

;			TRACK TITLE

[MeterTitleArtistFunction]
Meter=Shape
Group= ActivatedMeters
X=#LeftIndent#
Y=0
Shape=Rectangle 0,0,#ContainerExpandWidth#,#ContainerWH#,#Radius# | Fill Color #BoxBGColor1# | StrokeWidth 0 | StrokeColor #FillColorL#
LeftMouseUpAction=!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1

[MeterTitle]
Meter=String
MeasureName=MeasureTitle2
Group = ActivatedMeters
X=7r
Y=4r
W=(#ContainerExpandWidth#-10)
H=16
FontFace=#Font1#
FontSize=10
FontWeight=600
FontColor=#AccentColor#
StringAlign=#TextAlign#
ClipString=1
AntiAlias=1
LeftMouseUpAction=!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1

;			TRACK ARTIST

[MeterArtist]
Meter=String
MeasureName=MeasureArtist
Group = ActivatedMeters
X=1r
Y=1R
W=((#ContainerExpandWidth#)-25)
H=16
FontFace=#Font1#
FontSize=8
FontWeight=500
FontColor= #TextColor#
StringAlign=#TextAlign#
ClipString=1
AntiAlias=1
LeftMouseUpAction=!CommandMeasure "MeasurePlayerSpotify" "OpenPlayer"
RightMouseUpAction=!CommandMeasure "MeasureWin7Audio" "ToggleMute"
MouseScrollUpAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume #Volume#"
MouseScrollDownAction=!CommandMeasure "MeasureWin7Audio" "ChangeVolume -#Volume#"
Hidden = 1
DynamicVariables = 1