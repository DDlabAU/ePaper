# Adafruit RED/BLACK/WHITE 1.5'' ePaper
## Info og Opstilling
![alt text](https://github.com/DDlabAU/ePaper/blob/master/Adafruit%201.54''%20tri-color%20ePaper%20display/ePaperOps%C3%A6tning.png "Opstilling")

[Source](https://learn.adafruit.com/adafruit-eink-display-breakouts/drawing-bitmaps "Adafruit display guide")

Displayet er 152x152 pixels.

Download adafruit EDP library i library manager

Download adafriut GFX libray i library manager.

Arduinos Library manager findes under fanemenuen *Sketch* -> *Include Library* -> *Manage Libraries...*.

_**LINK til basic arduino sketch, der gør displayet helt hvidt, hvori man kan indsætte funktionerne nedenfor.**_

Dette Arduino program kan bruges som skabelon for at kommunikere med ePaper displayet. Alle funktionerne man ønsker at bruge fra udvalget nedenfor tilføjes under kommentaren: `// YOUR CODE - add your graphics to the buffer`. Objektet hvorpå disse funktioner kan udføres hedder i programmet epd.

Efter installation af EDP biblioteket kan andre eksempler findes i Arduino under fanemenuen *Fil* -> *Eksempler* -> *Adafruit EPD*. Her er der bl.a. eksempelkode for hvordan man viser et bitmap på displayet, som er gemt på et seperat SD kort.

**NB!** Displayet virker ikke hvis der sidder et micro SD kort i, og man ikke ønkser at hente data fra det.

Efterlad altid displayet helt hvidt for at undgå misfarvning på displayet! Dette kan gøres enten med funktionen `clearDisplay()` eller `fillScreen(EPD_WHITE)` efterfulgt af funktionen `display()`. (Dette kan også gøres ved at køre eksempelkoden _**ePaperBasic(LINK)**_, uden at foretage nogen ændringer i koden).

Opdater **IKKE** grafikken på displayet mere end hvert 180. sekund (dvs. hvert 3. minut)!
Prøv derfor så vidt muligt at placere al koden der sender data til displayet i `setup()`. Hvis dette ikke er muligt, vær meget opmærksom på hvor ofte data sendes til displayet.

Virker ved at skrive alt der ønskes vist på displaet til bufferen, efterfulgt af `display()` funktionen, der så viser dataen og tømmer bufferen.

## Farver
```Arduino
EPD_WHITE
```
Angiver farven *hvid* på displayet.

```Arduino
EPD_BLACK
```
Angiver farven *sort* på displayet.

```Arduino
EPD_RED
```
Angiver farven *rød* på displayet.


## Funktioner

**Alle funktioner nedenfor skal bruges på det objekt der refererer til displayet med punktnotation!**
Dvs. I eksempelkoden _**LINK**_ bruges funktionerne ved f.eks. at skrive: `epd.display()`.

### Basic
```Arduino
display()
```
Viser data gemt i bufferen på displayet. Dvs. Den tegner de funktioner man har brugt siden sidste gang `display()` funktionen blev brugt.

```Arduino
clearBuffer()
```
Tømmer bufferen. Bufferen er der hvor al data om det man vil vise på displayet gemmes indtil man bruger `display()` funtionen til at få det vist på displayet.

```Arduino
clearDisplay()
```
Fjerner alt der er på displayet. Den efterlader displayet helt hvidt.
Brug denne funktion hver gang du efterlader displayet for at undgå misfarvning.

```Arduino
width()
```
Returnerer bredden af displayet i pixels.

```Arduino
height()
```
Returnerer højden af displayet i pixels.

```Arduino
fillScreen(c)
```
Udfylder hele displayet med én farve (rød, sort eller hvid).
Parameteret `c` er den farve man ønsker, angivet som beskrevet under afsnittet *Farver* ovenfor.

### Former
```Arduino
drawPixel(x, y, c)
```
Tegner én pixel på koordinatet (`x`,`y`) på displayet. Parameteret `c` angiver farven på pixelen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawFastHLine(x, y, width, c)
```
Tegner en horisontal linje med startpunkt i koordinatet (`x`,`y`) der strækker sig `width` langt hen mod højre fra startpunktet.
Parameteret `c` angiver farven på pixelen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawFastVLine(x, y, height, c)
```
Tegner en vertikal linje med startpunkt i koordinatet (`x`,`y`) der strækker sig `height` langt lodret ned fra startpunktet.
Parameteret `c` angiver farven på pixelen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawLine(x1, y1, x2, y2, c)
```
Tegner en linje mellem koordinaterne (`x1`,`y1`) og (`x2`,`y2`). Parameteret `c` angiver farven på linjen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawRect(x, y, width, height, c)
```
Tegner en udfyldt rektangel, hvor (`x`,`y`) er koordinatet for firkantens øverste venstre hjørne. `width` og `height` svarer til hhv. bredden og højden af firkanten i pixels. Parameteret `c` angiver farven på firkanten, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
fillRect(x, y, width, height, c)
```
Tegner omridset af en rektangel, hvor (`x`,`y`) er koordinatet for firkantens øverste venstre hjørne. `width` og `height` svarer til hhv. bredden og højden af firkanten i pixels. Parameteret `c` angiver farven på firkanten, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawRoundRect(x, y, width, height, curve, c)
```
Tegner omridset af en firkant med afrundede hjørner. (`x`,`y`) svarer til positionen af firkantens øverste venstre hjørne. `width` er den ønskede bredde på firkanten of `height` er den ønskede højde på firkanten i pixels.`curve` er den grad af afrundede hjørner man ønsker, dvs. hvis man sætter denne højt nok vil firkanten blive til en oval. Parameteret `c` angiver farven på omkridset, angivet som beskrevet under afsnittet *Farver* ovenfor.


```Arduino
fillRoundRect(x, y, width, height, curve, c)
```
Tegner en udfyldt firkant med afrundede hjørner. (`x`,`y`) svarer til positionen af firkantens øverste venstre hjørne. `width` er den ønskede bredde på firkanten of `height` er den ønskede højde på firkanten i pixels.`curve` er den grad af afrundede hjørner man ønsker, dvs. hvis man sætter denne højt nok vil firkanten blive til en oval. Parameteret `c` angiver farven på firkanten, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawCircle(x, y, radius, c)
```
Tegner omridset af en cirkel. (`x`,`y`) svarer til positionen af cirklens centrum. Parameteret `radius` er den ønskede radius på cirklen i pixels. Parameteret `c` angiver farven på omridset, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
fillCircle(x, y, radius, c)
```
Tegner en udfyldt cirkel. (`x`,`y`) svarer til positionen af cirklens centrum. Parameteret `radius` er den ønskede radius på cirklen i pixels. Parameteret `c` angiver farven på cirklen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
drawTriangle(x1, y1, x2, y2, x3, y3, c)
```
Tegner omridset af en trekant. Koordinaterne (`x1`,`y1`), (`x2`,`y2`) og (`x3`,`y3`) svarer til de tre punkter, der forbindes for at tegne trekanten. Parameteret `c` angiver farven på cirklen, angivet som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
fillTriangle(x1, y1, x2, y2, x3, y3, c)
```
Tegner en udfyldt trekant. Koordinaterne (`x1`,`y1`), (`x2`,`y2`) og (`x3`,`y3`) svarer til de tre punkter, der forbindes for at tegne trekanten. Parameteret `c` angiver farven på cirklen, angivet som beskrevet under afsnittet *Farver* ovenfor.

### Tekst
```Arduino
setTextSize(s)
```
Sætter den ønskede tekststørrelse på tekst, der skal vises på displayet. Parameteret `s` angiver størrelsen.

```Arduino
setCursor(x, y)
```
Positionér der hvor du vil skrive din tekst med `print()` funktionen. (`x`,`y`) svarer til koordinatet, af det øverste venstre hjørne af teksten.

```Arduino
setTextColor(c)
```
Vælger farven på tekst, der skal vises på displayet. `c` står for farven, der skal angives som beskrevet under afsnittet *Farver* ovenfor.

```Arduino
setTextWrap(bool)
```
Begrænser området for ens tekst, så den laver automatisk linjeskift når den når til kanten af displayet. Parameteret `bool` angives som enten `true`, for at aktivere begrænsningen eller `false`, deaktiver begrænsningen.

```Arduino
print(text)
```
Sender ønsket tekst til buffer. Parameteret `text` står for den tekst man vil have vist.

```Arduino
println(text)
```
Send ønsket tekst efterfulgt af et linjeskift til buffer. Parameteret `text` står for den tekst man vil have vist.
