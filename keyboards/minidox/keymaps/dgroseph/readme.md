# Minidox Layout by dgroseph

This is a QWERTY minidox training layout merging my favorite features of 
* [dustypomerleau](../dustypomerleau),
* oprietop,
* [tw1t611](../tw1t611), and 
* germ's [gergoplex layout](https://github.com/germ/qmk_firmware/blob/044c614c181ac9f4aed7c675089d4cd0b573a442/keyboards/gergoplex/keymaps/default/keymap.c) which taught me how to use combos.

# Layers

| Layer | What's Up |
| ----- | ------ |
| QWERTY  | A simple QWERTY layer with an apostrophe instead of a semicolon, with Kinesis-Advantage-like thumb clusters|
| QWERTY Combos | a dense cover of two-key combos to get this 30% base layer into at least a 50% keyboard and mouse all on the base layer |
| NUM | A tenkey on the right hand that meshes with a numeric top row, and fills in the rest of the left hand with the rest of the numbers and operations |
| SYM | Gotta have the symbols, with some extra NAV sprinkling in there |
| NAV | A lot of movement options.  A bit crowded and could use some more adjustments, but very happy with the ALT-TAB macro |
| FUN | super fun |
| SYS |  |

## QWERTY

The methodology here is

* an apostrophe is worth way more on a 30% layout than a semicolon,
* I like the Kinesis advantage thumb clusters so I'm trying to fit everything in there with mod-taps and layers, and 
* a heavy dusting of combos makes the 30% life luxuriously functional with fewer taps and fingers.

```
/* QWERTY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NAVHOM|NUMEND|      |    |      |SYMPGU|NAVPGD|
 *                  `-------------| CTLBK|    | SFTSP|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```

 ## QWERTY Combos

The methodology here is

* while I don't miss moving my pinky out to a 6th column, I do miss those keys--let's put them as 5th-4th column combos;
* while I tried out [dustypomerleau](../dustypomerleau)'s layer-persistent hand-symmetric home-row mod-taps, I just couldn't get the timing to work well and I'm just too sloppy a fast typist to make that work--so let's put those as combos on the bottom row;
* having a NAV layer is good, but not good enough--so let's put a right-handed mouse and a left-handed d-pad at the center of each hand;
* `space` is on the right, and `delete` is on a thumb layer, so put those at the left index finger to balance things out;
* `quote` and `double quote` are great but as a software developer, I need `colon` and `semicolon` and the bracing nearby as wel--so put those at the index fingers in the remaining places that make sense.

 ```
 /* Combos on the base layer
 * inspired by germ's gergoplex layout
 *
 * ,----------------------------------.           ,----------------------------------.
 * |     ESC     |      |      (      |           |      )    BTN1    BTN2  BKSPC    |
 * |------+------+--UP--+---{--+--DEL-|           |---:--+--}---+-MSUP-+------+------|
 * |     TAB   LEFT    RGHT    [      |           |      ]    MSLF    MSRT  ENTER    |
 * |------+------+--DN--+------+--SPC-|           |---;--+------+-MSDN-+------+------|
 * |    SHIFT  CTRL    ALT    GUI     |           |     GUI    ALT    CTRL  SHIFT    |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.     ,------,-------------.
 *                  |      |      |      |     |      |      |      |
 *                  `-------------|      |     |      |------+------.
 *                                |      |     |      |
 *                                `------'     `------'
 */
 ```

 ## NUM

 The methodology here is

* I want a tenkey,
* I want all the numbers available to both hands,
* I want to do math with these numbers as well,

and we should access this layer with the left thumb because the right will be dancing around on the tenkey. 

 ```
 * NUM
 * Number - Focus on one-handed use and numpad on right from tw1t611
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |           |   _  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   /  |   .  |   *  |   +  |   -  |           |   -  |   1  |   2  |   3  |   =  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|      |      |    |      | FUN/0|   .  |
 *                  `-------------|      |    | ENTER|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```

 ## SYM

The methodology here is:

* get all the shifted symbols from the numeric top row all in the top row,
* fill in the rest of the right hand with the rest of the symbols,
* daily use let me know that combos were insufficient for some of the NAV work that I need--add GUI-directions for window movement and CTL-{left,right} for text navigation.  I still need to add CTL-{-,+} for code navigation, but you can tell how important that has been.

Also, we should access this layer with the opposite thumb of NUM because these often go together in the breaks between numbers.

```
 /* SYM
 * Symbol - Focus on one-handed use from tw1t611, symbol layer from oprietop's Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |  (   |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | CTLLT| GUIUP| CTLRT|      |           |   `  |   ;  |   :  |  [   |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      | GUILT| GUIDN| GUIRT|      |           |   ~  |   \  |   |  |  {   |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |NUM LK|  FUN |      |    |      |      |SYM LK|
 *                  `-------------|  DEL |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```

 ## NAV

The methodology here is

* gotta have your arrows,
* gotta have your mouse,
* gotta have your lock toggles,
* but also some special macros for 
  * ALT-TAB and SFT-ALT-TAB that took far too long to figure out and
  * opening a new tab and searching for the selected word.

The latter is cute, the former was very interesting.  The [Super ALT↯TAB](https://beta.docs.qmk.fm/features/feature_macros#super-alt-tab) laid out by QMK just wasn't going to cut it for me--I hang around lazily looking for my window in the list and couldn't have the TAB tapping be on a fixed countdown.  Then, I had the bright idea of using the layer-key to resemble the ALT and the ALTTAB taps resembling the TAB tapping, but to find the release of the layer key I had to explode LT() in `process_record_user` and then I could unregister ALT on my own.  Phew.  Same thing for SFT-ALT-TAB nearby.  While I'm pretty sure some of the work could be made more clear and better beyond my imagination with TAP-DANCE, I'm just not ready for that yet for some reason.  I know that I'll try to do with tap-dance what I did with combos and that's scares me.

NAV could be done from either hand, so put a layer trigger for it on each hand.

```
 /* NAV
 * Navigation + mouse keys
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  ESC |SFALTB|CTLCTV|ALTTAB|      |           | PAUSE| ACL0 | ACL1 | ACL2 | PSCR |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  TAB | HOME |  UP  |  END | PGUP |           | WH U | BTN1 | MS U | BTN2 |  INS |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS | LEFT | DOWN | RGHT | PGDN |           | WH D | MS L | MS D | MS R | SCRLK|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |  SYS |NUM LK|      |    |      |SYM LK|  SYS |
 *                  `------+------|NAV LK|    |SYS LK|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```

 ## FUN

 The methodology here is

 * all FN keys on each hand.

 We copied the NUM layer for assignment, but there are more, so it's pretty full with just that.  Nice to have some room to play around, though!

 Having the NUM and SYM thumbs trigger FUN is a nice way to get more layers out of just 6 keys on two thumbs, while keeping some symmetry.  The SFT and CTL from the thumbs should carry over here, as should the QWERTY combo mods, which are all part of the holistic hand-agnosticism (HHA (R)(C)(TM)) as an ideal.

 ```
 /* FUN (NUM + SYM)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           |      |  F4  |  F5  |  F6  |  F11 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |  F11 |  F12 |           |      |  F1  |  F2  |  F3  |  F12 |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |TSKMGR|      |      |    |      |      |CALTDE|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```

 ## SYS

 The methodology here is

 * there are so many more things that QMK can do!

To squeeze another layer into two thumbs with 6 keys that keeps HHA in mind while having the innermost thumbs stay mod-taps instead of layer-taps, we take the two NAVs together to be the SYS layer.

 Here we have a lot of room for more power to this keyboard layout, which is very exciting.  For now, make sure we can pause without being in the app and reset the keyboard to flash the next exciting version of the firmware.

 ```
 /* SYS (NAV + NAV)
 * System, media, and layer lock keys from dustypomerleau
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RESET| DEBUG|QWERTY|      |      |           | VOL- | VOL+ | MUTE | VOL--| VOL++|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SHIFT| CTRL |  ALT |  GUI |BRITE+|           |      | MRWD | MPLY | MFFD |      |
 * |------+------+------+------+------|           | -----+------+------+------+------|
 * |      |      |      |      |BRITE-|           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |NUM LK|      |    |      |SYM LK|      |
 *                  `-------------|NAV LK|    |SYS LK|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
 ```