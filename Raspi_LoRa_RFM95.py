from RFM95 import *
import timefrom RFM95 import *
import timefreqBand=434.0
nodeID=0
networkID=1
intPin=8
rstPin=22
spiBus=0
spiDevice=0
print('Radio initialising...')
rfm95=RFM95(freqBand=freqBand,nodeID=nodeID,networkID=networkID,intPin=intPin,rstPin=rstPin,
spiBus=spiBus,spiDevice=spiDevice)
print('Success!')
print('RF95 node #'+str(nodeID)+' init OK @ '+str(freqBand)+'MHz')
print('Listening packet...')
while True:    
  buf=[]
  if rfm95.available():        
    if rfm95.recv(buf,RF95_MAX_MESSAGE_LEN):
     print('Packet['+str(len(rfm95.lastMessage))+'] #'+str(rfm95.rxHeaderFrom)+' => #'+str(rfm95.rxHeaderTo)
      +' '+str(rfm95.lastRSSI)+'dB: '+rfm95.lastMessage)
        time.sleep(2)
