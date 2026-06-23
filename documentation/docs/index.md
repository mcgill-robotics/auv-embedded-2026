# Welcome to the home page for the Hydrophone shield design documentation.

For full documentation visit [mkdocs.org](https://www.mkdocs.org).

To look into for later 

https://www.analog.com/en/resources/analog-dialogue/articles/front-end-amp-and-rc-filter-design.html

## Notes about KiCad

The KiCAD project can be found under the `kicad` folder. The project is organized in the following way : 

- `ADC.kicad_sch` main schematics file (other `.kicad_sch` are hierarchical subsheets)
- libraries are in the `kicad/libraries` folder. The libraries are organized in the following way : 
  - `kicad/libraries/footprints` contains all the footprints used in the project
  - `kicad/libraries/symbols` contains all the symbols used in the project
  - `kicad/libraries/3dmodels` contains all the 3D models used in the project

If for some reason a component's footprint or symbol is not found, double check the include path in `Preferences -> Configure Paths`