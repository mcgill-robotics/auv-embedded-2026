## Power components in the PCB design 

The power components are made up by :

* the standalone LDOs which regulate power for the digital power supplies
    * ADP7118-3.3
    * ADP7118-1.8
* the precision references which are used to set common mode voltages and as the main ADC reference voltage
    * LTC6655B-2.5
    * LTC6655B-1.25
* The dual-supply with boost and inverting charge pump to power the LTC6373 (PGA) with symetric positive and negative supply rails
    * LTC3265

## The LTC3265 (dual supply)

- I chose the TSSOP package instead of the DFN package to make it easier for soldering
- TODO : carefully place and route the LTC3265 in such a way that : 
  1. the fast-switching nets (\(C_{BST+},C_{BST-},C_{INV+},C_{INV-}\)) do not inject noise into analog signal nodes like `ADJ+` and `ADJ-`
  2. the power disspiation is maximized (placing the IC on a corner?) so that thermal heat doesn't build up around the IC
- Choose X5R or X7R ceramic capacitors, they are less sensitive to temperature increases
- The LTC3265 features one _Boost charge pump (which doubles the input voltage)_ coupled to a post-boost LDO, and an _inverting_ charge pump (which generates \(V_{out-}=-V_{IN_N}\)). By connecting \(V_{out+}\) and \(V_{IN_N}\) together we are generating symetric output rails. 
- the `RT` is connected to GND so that the charge pumps work at the maximal constant switching frequency (about 500kHz)
Typical dropout voltages for LDO output pins are given in the table
- According to the datasheet _In constant frequency mode (MODE=0) the values of C_out+ and C_out- directly control the amoubnt of output ripple for a given load current_. The output ripple peak-to-peak voltage being proportional to the load current and inversely proportional to the output capacitance, we cchoose a 100uF capacitance for C_out- and C_out+. The startup time (`t_on`) will be larger but that is not a problem for us. 



Dropout voltage for positive and negative LDOs

| \(V_{dropout_{LDO+}}\) | \(V_{dropout_{LDO-}}\) |
|------------------------|------------------------|
| 400 to 800 mV          | 200 to 500mV           |

Therefore with a 5V input, we cannot directly generate a stable -5V rail on `LDO-` unless we configure the LTC3265 in symetric mode. 
In that case the maximum post-LDO voltages are about +/- 9V. This gives a very comfortable headroom for the PGA chip.

- Q : what is quiescent current ??

## The LTC6655 (voltage references)

- Dropout voltage is about 500mV, maybe we could connect the first LDO in "chain" with the second one (5V -> 2.5V -> 1.25V instead of 5V -> 1.25V and 5V - >2.5V)
- We chose the 8-lead MSOP package for the simpler soldering. 
- There is a `-NR` (for Noise reduction) package which features a `NR` which we can connect to 0.1uF capacitor for improved noise reduction. 

!!! note "Question about \(V_{LDO+}\) and \(V_{LDO-}\)"
Although the voltage rails can go as high as +/- 9V, is there a sweet spot between power disspated from shifting down \(V_{OUT-/+}\) to \(V_{LDO-/+}\ (the power disspated by the LDO is proportional to these voltage drops) and reasonable headroom in LT6373 power rails ? Figure that out

## The ADP7118 (voltage regulators for 3.3V and 1.8V)

- The dropout voltage is typically 200mV, so we might be able to _chain_ the 1.8V and 3.3V LDOs together instead of connecting each independently to the 5V. 
- Chose the 8-lead SOIC option 
