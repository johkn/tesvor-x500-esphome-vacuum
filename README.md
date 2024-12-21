# tesvor-x500-esphome-vacuum
Work in Progress.  Control and read state of Tesvor X500 vacuum robot via esphome

Sources/Inspiration

https://templates.blakadder.com/dealdig_Robvaccum_8.html

https://github.com/arendst/Tasmota/discussions/19554#discussioncomment-8820956


An ESP12S is built into the robot vacuum cleaner, on a separate circuit board.

ESP flash with the x500.yaml

The following functions/status queries are currently possible.

Functions:

-Smart cleaning
-Spot cleaning
-Stop
-Back to station
-Forward, backward, left and right

Status:

-Idle
-Cleaning
-Charging
-Docked 

To-do list:

-Battery indicator
-Cleaned area
-Map (a map of the cleaned area was displayed in the cloud app)

vacuum.yaml extension for configration.ymal so that the X500 is recognized as a vacuum robot:

vacuum.yaml
