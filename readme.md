# Die-On-Seven-Seg

### About:

Press a button, a random number will be generated and displayed until the button is pressed again.

### Using:

##### Inputs

Should be relatively obvious if you read the source:

| Die Size | Pin |
| -------- | --- |
| d6       | 2   |

##### Outputs

Seven Segment LCD display:

| digit | Seven Segment Pin | Arduino Pin | 
| ----- | ----------------- | ----------- |
| ones  | -                 | -           |
| -     | 1                 | 7           |
| -     | 2                 | 6           |
| -     | 3, 8              | GND         |
| -     | 4                 | 5           |
| -     | 5                 | -           |
| -     | 6                 | 4           |
| -     | 7                 | 3           |
| -     | 9                 | 8           |
| -     | 10                | 9           |

### Todo:

* short graphical "rolling" animation

* "clear" function
