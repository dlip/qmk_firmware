# Stained Layout

This is a computer generated layout I created in a fork of keyboard layout optimizer https://github.com/dlip/keyboard_layout_optimizer and have designed some new metrics for use with "directional keyboards" like Harite.

This layout is geared towards rolls and mainly using the index, middle and ring fingers, but using the following metrics you can generate layouts suited to your tastes with thumb alphas etc.

Bigram Metrics
Same Finger Scissors: Going North to South or East to west on the same finger
Directional Change: Changing direction on different fingers on the same hand

Trigram Metrics
Same finger rolls: Rolling 2 characters on one finger, then pressing any key on the other hand
Same finger onehands: Rolling 3 characters on 1 finger
Unidirectional Rolls: Rolling 2 characters on different fingers, in the same direction on one hand, then pressing any key on the other hand
Unidirectional Onehands: Rolling 3 characters on different fingers, in same direction on one hand

```txt
          LEFT HAND                         RIGHT HAND

  Pinky   Ring    Middle  Index     Index   Middle  Ring    Pinky

    q       f       w       o         l       u       b       z
  \   '   x   k   y   h   m   c     i   g   r   v   p   j   ;   /
    ,       s       t       a         n       e       d       .

                      Thumb          Thumb

                      Num           DelWord
                  Spc MseM  MseR   Esc   Bspc
                      MseL           Enter

Layout string (layer 1):
fxkswyhtomcalignurvebpjd

Unigram metrics:
  Not found: 0.2689% of 1.0000
    96.51 Finger Balance                      | Finger loads % (no thumb): 1.6 9.5 17.3 21.0 - 20.0 21.7 7.4 1.4
     0.33 Hand Disbalance                     | Hand loads % (no thumb): 49.45 - 50.55
   274.67 Key Costs                           | Worst unigrams: i (10.33%), r ( 8.78%), s ( 6.99%)

Bigram metrics:
  Not found: 0.4501% of 1.0000
     4.67 Same Finger Scissors                | Worst: ig (28.41%), gi (15.29%), ue (13.71%);  Worst non-fixed: ig (28.41%), gi (15.29%), ue (13.71%)
    65.90 Directional Change                  | Worst: to ( 7.17%), ha ( 5.86%), le ( 5.17%);  Worst non-fixed: to ( 7.17%), ha ( 5.86%), le ( 5.17%)

Trigram metrics:
  Not found: 0.8231% of 1.0000
   -26.09 Unidirectional Rolls                | Worst: and ( 6.59%), ent ( 4.58%), for ( 4.42%);  Worst non-fixed: and ( 6.59%), ent ( 4.58%), for ( 4.42%)
    -3.09 Unidirectional Onehands             | Worst: sta (38.07%), den (15.36%), pri (13.72%);  Worst non-fixed: sta (38.07%), den (15.36%), pri (13.72%)
   -71.14 Same Finger Rolls                   | Worst: the (13.70%), her ( 2.38%), ter ( 2.14%);  Worst non-fixed: the (13.70%), her ( 2.38%), ter ( 2.14%)
   -19.55 Same Finger Onehands                | Worst: ing (52.57%), ver (13.64%), com (10.03%);  Worst non-fixed: ing (52.57%), ver (13.64%), com (10.03%)
    69.13 Alternates                          | Worst: tio ( 3.84%), his ( 2.38%), out ( 1.79%);  Worst non-fixed: tio ( 3.84%), his ( 2.38%), out ( 1.79%)
    34.24 Alternates (sfs)                    | Worst: ion ( 9.70%), wit ( 4.83%), ear ( 3.45%);  Worst non-fixed: ion ( 9.70%), wit ( 4.83%), ear ( 3.45%)

Cost: 425.57 (optimization score: 234978)
```
