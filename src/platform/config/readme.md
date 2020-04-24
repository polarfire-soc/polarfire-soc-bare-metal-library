===============================================================================
# MPFS HAL config folder
===============================================================================

The MPFS HAL config folder (platform/config) provides configuration for the MPFS HAL.

There are three sub folders below the folder /platform/config/

* hardware
* linker
* software

### The hardware folder is the output from Libero.

   Libero input through header files located in the config/hardware under the 
   platform directory. These files are generated using the PF SoC embedded 
   software configuration generator. It takes an xml file generated in the Libero 
   design flow and produces header files based on the xml content in a suitable 
   form for consumption by the MPFS HAL.
   
### The linker folder

   The linker folder contains a sub folder with example linker scripts.
   
### The software folder

   The software folder conatins the software configuration for the project.

### Project directory strucutre, showing where config folder sits.

~~~~
   +---------+      +-----------+                      +---------+
   | src     +----->|application|                  +-->|hardware |
   +---------+  |   +-----------+                  |   +---------+
                |                                  |
                |   +-----------+                  |   +---------+
                +-->|modules    |                  +-->|linker   |
                |   +-----------+                  |   +---------+
                |                                  |
                |   +-----------+     +---------+  |   +---------+
                +-->|platform   +---->|config   +--+-->|software |
                    +-----------+  |  +---------+      +---------+
                                   |
                                   |  +---------+
                                   +->|hal      |
                                   |  +---------+
                                   |
                                   |  +---------+      +----------+
                                   +->|drivers  +----->|mss_uart  |
                                   |  +---------+      +----------+              
                                   |
                                   |  +---------+      +----------+
                                   +->|mpfs_hal +----->|nwc       |
                                      +---------+      +----------+
                                      
~~~~	  

Note: The current content of the platform/config folder contains configuration for targeted at the PF_SOC_PERIPHERAL_BASE_BOARD.
