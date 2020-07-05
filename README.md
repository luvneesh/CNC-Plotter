# Ta 202 Project Report

# CNC Printer v2



 ![](RackMultipart20200705-4-1srqmzr_html_d9d11931ee6d8dd3.png)


Group: 33

Prof Mohit Law

## Manufactured Parts Table

| Name | Qty | Material | Manufacturing |
| --- | --- | --- | --- |
| Base | 1 | Wood | Bandsaw + drilling |
| Lower bracket | 1 | ABS/PLA | 3D printing |
| Lower bearing mount | 1 | ABS/PLA | 3D printing |
| Lower nut | 1 | Mild steel | Bandsaw, welding |
| Table | 1 | Acrylic | Laser-cut |
| L clamps | 2 | ABS/PLA | 3D printing |
| MS angles | 2 | Mild steel | Bandsaw + drilling |
| Cross-Bar | 1 | ABS/PLA | 3D printing |
| Pencil holder system | 1 | ABS/PLA | 3D printing |
| Upper motor mount | 1 | ABS/PLA | 3D printing |
| Upper bearing mount | 1 | ABS/PLA | 3D printing |
| Upper nut | 1 | Mild steel | Bandsaw, welding |
| Upper supports | 2 | Mild Steel | Bandsaw, drilling |
| Side supports | 2 | ABS/PLA | 3D printing |
| Lead screw | 2 | Stainless Steel | Turning on Lathe |

##


## Acquired Parts Table

| Name | Qty | Material | Description |
| --- | --- | --- | --- |
| Standoffs | 2 | Brass | M3, 10mm, M to F |
| Motors | 2 |
 | NEMA 17 Stepper motor, 5.5 Kgm |
| A4988 | 2 |
 | Stepper motor driver, phase current 1 A |
| Microcontroller | 1 |
 | Arduino Mega |
| Shafts for support | 2 | ss | 2 mm (|) shaft |
| Battery | 1 |
 | 3 cell Lipo |
| Servo motor | 1 |
 | Sg90 basic servo |
| Ball bearings | 2 | ss | 4MM ID, 16 OD, cylindrical ball bearing. |
| Nuts, Bolts, and washers | 24 | SS | M3, 8 mm |
| Cable ties (to secure pen) | 5 |
 | Medium size |
| Nuts | 4 | SS | M10 |
| Sd card shield | 1 |
 | To read nc code |

## Lead screw calculations

Size = M10

Pitch = 2mm

Speed ratio = 1:1

Lead =2mm

Moment of inertia = 0.00027 Kg cm^2

Lower screw

Max travel = 100mm-6 mm =94 mm

Max Rev = 47

Upper screw

Max travel = 150mm-6 mm =144 mm

Max Rev = 72

Minimum rotation = 1.8 deg **(single-phase operation only )**

of stepper motor

Minimum Travel = 2mm/ 360 \*1.8 = **0.01 mm**

Default angular vel = 10\* 2pi /2 = **10pi /sec = 300 RPM**

## NC Codes Supported

M03 : Pen Down

M05 : Pen Up

G31 : **Incremental approach only.**

M71 : **Metric units only**

F : Feed (default = 10 mm/sec [**600**],

Max = 20 mm / sec [**1200**])

G01 : Linear interpolation

_G02/03 : circular interpolation:_ **reinterpreted in the form of G01 (unicorn)**

M30 : program end

**Notes:**

- G code file must be saved as &#39;NC.txt&#39; in the attached sd card. Or can be entered incrementally using the serial monitor.
- **G code can be most easily generated using Inkscape: save as g code.**
- The pen moves to 0,0 (front right end) at the start of the program.
- Xmax =144 mm Xmin =0.01 mm
- Ymax = 94 mm Ymin =0.01 mm
- It is advisable not to run at peak rpm (feed) for long durations (limitation of motor driver) run at default rpm only.
- Use Normalizefeed() to set to default feed line by line, (optional) commented out in main.ino
-

## Attachments

- Model files, .step, f3d
- Project report file
- Video of exploded view. Assembly, 360-degree view
- ino, : checks if given gcode is supported
- ino : Runs code from NC.txt
- ino : Runs Code from serial monitor
- h : Header file for translation
- h : contains the normalized feed function
- h : Header file for motor functions and tests

## Future possibilities

- Adding onboard computer with display for user-friendly selection or editing of programs, reading from sd card.
- Adding time of flight sensors for active feedback on table and pen position as well as correction overtime
- Addition of Keypad for manual entry of coordinate points
- Addition of vertical leadscrews and conversion into full 3d printer
- Weight reduction and complete switching to 3d printed parts.
- Upgrade of the motor driver for faster printing