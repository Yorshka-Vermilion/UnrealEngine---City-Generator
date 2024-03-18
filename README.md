# UnrealEngine---City-Generator
Procedural city generator with settings for roads complexity, development areas, buildings and nature.

# Screens

![obraz](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/aef44170-253c-463d-ba38-6c3feab0bdb2)
![obraz](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/09cfd2c6-3f9a-4078-ad88-5e7886381901)
![obraz](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/0d6b380b-df5f-4344-907d-434774d8bbca)

# Preview

### City 1 (higher development)

https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/ddd2fe53-cbce-46ec-a9cd-cb63d8723e3a

### City 2 (lesser development)

https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/4f5cba41-262a-471d-a1fe-6eabb50f6b8a

# Customization 

![Przechwytywanie](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/eb90f46b-fd1c-4653-9d36-dee701f9e0f2)

## CityGenerator

### Performance
- **Max New Plates on Frame** - how many new objects can be placed on one frame. With beefy system you could go higher without stutters.
### Parameters
- **City Radius** - radius of a town
- **Road parameters** - array of road types
  - **Length** - maximum length of one street (x and y). Setting both parameters to the same value will result in square town. 
  - **DirChangeChance** - chance of changing direction of a street (x and y)
  - **BreakpointChance** - chance to split street into two or three (x and y)
  - **DowngradeChance** - chance to downgrade road type to lower tier. If no lower tier is present, street is finished.
  - **BuildingChance** - how likely is to spawn building next to this type of road. (it is also affected by other parameters)
  - **Radius wieight** (Breakpoint/Downgrade/Building) - how much distance from center of a town affect chances of breakpoint/downgrade/bulding.
  ![Przechwytywanie](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/aa8e8c6d-b148-454f-8d39-ef0281857d4b)
- **Buildings** - array of possible buildings
- **Enviroments C** - array of posible enviromental structures
- **Development** (0-1) - how much city is developed. High development means more skyscrapers (blue buildings - Tier 1), bigger city centre, and more Tier 1 roads.
- **New building chance** - chance for new building to appear after road generation phase is completed (chance decreses with distance from the city center)
- **Scale varriness** - varriness of a scale of a buildings
- **Road materials** - array of road materials
- **Road type scales** - array of scales for given roads, it lets you decice how narrow roads are on particural tier
- **Spawn Z** - it is only for simulation purposes, it is height from which building is falling
- **City material** - material for buildings

## Building

All buildings are declared separately. You want to make an object of a "Building class". Here are parameters that you can set:

![obraz](https://github.com/Yorshka-Vermilion/UnrealEngine---City-Generator/assets/59543577/55908579-ae1a-4731-994b-bb0c8119d796)

- **Size** - size (%) of a mesh
- **Randomness** - power of random size, rotation and displacement
- **Fall Speed** - speed of a "falling" animation in simulation
