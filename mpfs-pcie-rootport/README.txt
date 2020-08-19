================================================================================
                PolarFire SoC PCIe Read and Write Application
================================================================================

This example project demonstrates the PolarFire SoC PCIe root port data read and 
write operation with the PCIe endpoint. It is targeted to the PolarFire SoC model
on Renode emulation platform for PCIe RootPort and Endpoint.

--------------------------------------------------------------------------------
                            How to use this example
--------------------------------------------------------------------------------
Run the example project using a debugger on E51(hart0). Place watches on the 
pointer p_pcie_end_point. You will then be able to observe the content of 
p_pcie_end_point being written into PCIe endpoint memory and read back from
PCIe endpoint memory. Open a debugger memory window to view the content of 
p_pcie_end_point address.

--------------------------------------------------------------------------------
                                Target hardware
--------------------------------------------------------------------------------
This example project can be used on the PolarFire SoC model on Renode emulation 
platform. 

There are configurations that need to be set for this example project. The
configurations are categorized into hardware and software configurations.
The hardware configurations are located in ./src/boards/<target_board> folder.
The default software configurations are stored under 
.src/platform/platform_config_reference folder.

The include files in the "./src/boards/<target_board>/soc_config" folder define 
the hardware configurations such as clocks. You must make sure that the 
configurations in this example project match the actual configurations of your 
target design that you are using to test this example project.

If you need to change the software configurations, you are advised to create a 
new folder to replicate this folder under the ./src/boards directory and do the 
modifications there. It would look like 
./src/boards/<target_board>/platform_config

The include files in the "platform_config" folder define the software 
configurations such as how many harts are being used in the software, what is 
the tick rate of the internal timer of each hart. These configurations have no 
dependency on the hardware configurations in "soc_config" folder. Note that 
changing these software configurations may require a change in your application 
code.

## Executing project in the Renode emulation

To launch the PolarFire SoC Icicle board emulation model on Renode from 
SoftConsole, launch the preconfigured external tool from
   Run -> External Tools -> "PolarFire-SoC-Icicle-Renode-emulation-platform". 

This will also launch an UART terminal which works with Renode.

Build the project and launch the debug configuration named 
"mpfs-pcie-rootport renode all-harts debug.launch" which is configured for
Renode.
Alternatively, you can perform above two steps in one go by launching 
mpfs-pcie-rootport renode all-harts start-platform-and-debug.launch which
will launch the PolarFire SoC Icicle board emulation model on Renode and also
launch a debug session with it.

Further information on working with Renode is available from the "Renode 
emulation platform" section of the SoftConsole release notes. The SoftConsole
release notes document can be found at: <SoftConsole-install-dir>/documentation
