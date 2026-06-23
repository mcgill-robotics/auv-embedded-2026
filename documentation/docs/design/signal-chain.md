## Design of the Signal Chain 

The main components that make up the signal chain are : 

* The analog frontend, which consists of the hydrophone and the preamplifier (ADC driver ADA4950, a FDA)
* The DSP, which consists of the main ADC (AD4001) which sends the digitalized signal over SPI to the MCU
* The voltage reference block, which provides the ADC reference voltage as well as the FDA common mode voltage. 

![High level schematic of the signal chain](./images/signal-chain.png)

### Analog Frontend 

Current considerations to take into account for later and current iterations : 

* Make sure that the input and output voltage range swing is supported by the FDA, given its operating on a single supply
* Maybe add a provisional passive RC filter before the FDA to prevent aliasing of high frequency noise, and that cannot be undone digitally afterwards. Note that the RC filter between the FDA and ADC (aka the "kickback filter") serves a different purpose and does not substitute an anti-aliasing filtger.

### DSP

