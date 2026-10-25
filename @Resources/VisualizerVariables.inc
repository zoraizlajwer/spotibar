[Variables]
Bars=10
BarWidth=9
Space=3
BarHeight=33
MinHeight=9
BarRadius=2.0
; derived values
Range=(#BarHeight#-#MinHeight#)
Step=(#BarWidth#+#Space#)
TotalWidth=(#Bars#*#BarWidth#+(#Bars#-1)*#Space#)