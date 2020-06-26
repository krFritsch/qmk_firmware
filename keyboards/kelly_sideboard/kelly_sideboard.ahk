;  _  __    _ _          _____ _     _      _                         _ 
; | |/ /   | | |        / ____(_)   | |    | |                       | |
; | ' / ___| | |_   _  | (___  _  __| | ___| |__   ___   __ _ _ __ __| |
; |  < / _ \ | | | | |  \___ \| |/ _` |/ _ \ '_ \ / _ \ / _` | '__/ _` |
; | . \  __/ | | |_| |  ____) | | (_| |  __/ |_) | (_) | (_| | | | (_| |
; |_|\_\___|_|_|\__, | |_____/|_|\__,_|\___|_.__/ \___/ \__,_|_|  \__,_|
;                __/ |                                                  
;               |___/  
;
;

unassigned(key:=""){
ToolTip AHK: %key% is unassigned
Sleep 1000
ToolTip
return
}

#if (getKeyState("F23", "P")) ;This is the line that makes all the lines below possible.                                                                           

F23:: return ; 

; =====
; ----- row 1 col 1
0::unassigned("Single tap, row 1 col 1")
1::unassigned("Double tap, row 1 col 1")
; ----- row 1 col 2
2::unassigned("Single tap, row 1 col 2")
3::unassigned("Double tap, row 1 col 2")
; ----- row 1 col 3
4::unassigned("Single tap, row 1 col 3")
5::unassigned("Double tap, row 1 col 3")
; ----- row 1 col 4
6::unassigned("Single tap, row 1 col 4")
7::unassigned("Double tap, row 1 col 4")
; ----- row 1 col 5
8::unassigned("Single tap, row 1 col 5")
9::unassigned("Double tap, row 1 col 5")
; ----- row 1 col 6
a::unassigned("Single tap, row 2 col 6")
b::unassigned("Double tap, row 1 col 6")
; =====
; ----- row 2 col 1
c::unassigned("Single tap, row 2 col 1")
d::unassigned("Double tap, row 2 col 1")
; ----- row 2 col 2
e::unassigned("Single tap, row 2 col 2")
f::unassigned("Double tap, row 2 col 2")
; ----- row 2 col 3
g::unassigned("Single tap, row 2 col 3")
h::unassigned("Double tap, row 2 col 3")
; ----- row 2 col 4
i::unassigned("Single tap, row 2 col 4")
j::unassigned("Double tap, row 2 col 4")
; ----- row 2 col 5
k::unassigned("Single tap, row 2 col 5")
l::unassigned("Double tap, row 2 col 5")
; ----- row 2 col 6
m::unassigned("Single tap, row 2 col 6")
n::unassigned("Double tap, row 2 col 6")