# LoRa_code_bundle
LoRa code different versions



Step 1. LBT

Listen-Before-Talk(LBT) is a technique used in radio communications whereby a radio transmitters first sense its radio environment before it starts a transmission. Where, end device will enter Rx mode and check the interference signal level before starting the data transmission.

When we used only three nodes and send data in every second for 100 times using LBT technique, transmission accuracy was 100%. But, when we increased the number off devices to 10, transmission accuracy dropped to 89%. 

When end devices use LBT technique, before transmitting data they listen if any other end devices are transmitting, If any device is transmitting, they wait until the channel to be available. As the number of end devices increase and devices transmit data more frequently, LBT itself cannot guarantee the successful data transmission. Because, still there is probability of more than one devices transmitting data at the same time. 

**Solution

For accurate data transmission where there are multiple end devices, LBT technique is not enough. Additional to LBT, each end device sends same data multiple times and gateway keeps only one of them and ignores the rest. The assumption is that among multiple but same data at least one of them will be transmitted successfully.

**Experiment

In our experiment we used 10 Lora development boards as shown below. 1 as a LoraGateway and remaining 9 as end devices. 
