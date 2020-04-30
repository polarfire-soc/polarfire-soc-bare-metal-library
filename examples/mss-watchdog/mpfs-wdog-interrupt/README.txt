================================================================================
                    PolarFire SoC MSS Watchdog interrupt example
================================================================================

This example project demonstrates the use of the PolarFire SoC MSS Watchdog. It 
demonstrates the watchdog configurations, the time-out and the MVRP interrupts 
and their handling.

--------------------------------------------------------------------------------
                            How to use this example
--------------------------------------------------------------------------------
To use this project you will nee a UART terminal configured as below:
    - 115200 baud
    - 8 data bits
    - 1 stop bit
    - no parity
    - no flow control

The example project will display instructions over the serial port. A greeting
message is displayed on the terminal. Watchdog0, 1 and 2 are configured to 
generate MVRP and time-out interrupt at 10sec and 25sec after system reset 
respectively. Messages are displayed on the UART terminal as and when the events
happen. Finally the system will reset when the watchdog0 down counter reached
zero value.

--------------------------------------------------------------------------------
                                Target hardware
--------------------------------------------------------------------------------
This example project can be used on the PolarFire SoC model on PolarFire SoC 
FPGA family hardware platforms. 

There are configurations that needs to be set for this example project. The
configurations are categorized into hardware and software configurations and 
are respectively located in the following folders
    ./mpfs_config/hw_config
    ./mpfs_config/sw_config

The "hw_config" defines the hardware configurations such as clocks. You must 
make sure that the configurations in this example project match the actual 
configurations of your target design you are using to test this example project.

The "sw_config" folder defines the software configurations such as HART 
configurations. These configurations have no dependency on the hardware
configurations that you use. If you change these configurations, you may have 
to change the software code to work according to the new configurations that 
you use.

## Executing project on PolarFire SoC hardware

The same application can be used on PolarFire SoC hardware platform. The MMUART0
must be connected to host PC. The host PC must connect to the serial port using 
a terminal emulator such as Tera Term or PuTTY.

Build the project and launch the debug configuration named 
mpfs-wdog-interrupt hw-emulation all-harts Debug.launch which is configured for 
PolarFire SoC hardware platform.
