ALGORITHM

1. Start the program and define constants for 5 zones (Z = 5) and 7 days (D = 7).
2. Declare 2D arrays for daily temperature, humidity, and AQI, along with 1D arrays for averages, Green Index, and risk days.
3. Set a ready flag to 0 to track whether data has been entered.
4. Display a menu with options for data entry, viewing records, rankings, recommendations, and exit.
5. Read the user's choice and repeat the menu in a loop until the exit option is selected.
6. If any option other than data entry is chosen while ready == 0, ask the user to enter data first.
7. For data entry, loop through all 5 zones and 7 days to read temperature, humidity, and AQI values.
8. Validate that temperature is 10–50, humidity is 0–100, and AQI is 0–500; re-enter the day's input if invalid, then set ready = 1.
9. Calculate the 7-day average temperature, humidity, and AQI for each zone.
10. Count a day as a risk day for a zone if AQI > 150, temperature > 35, or humidity > 80.
11. Compute sub-scores for air, temperature, and humidity, resetting any negative score to 0.
12. Calculate the final Green Index for each zone using 0.4 * air + 0.3 * temp + 0.3 * humidity.
13. Sort the zones in descending order of their Green Index scores to display the rankings.
14. Print zone-wise health and environmental recommendations based on average thresholds.
15. Stop the program when the user selects the exit option.
