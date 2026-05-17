@@ Eng. Adel Shata 

.global reset
reset:
    ldr sp, = stack_top                 // Top Stack Address
    bl WeStartHere_NotFromMain          // start from WeStartHere_NotFromMain rather than main
stop: b stop
