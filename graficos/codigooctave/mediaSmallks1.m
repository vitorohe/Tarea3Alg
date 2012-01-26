function[] = mediaSmallks1

%Test k=1 s=1:
%Binary Heap:
idiBH1 = [343876 338343 335689 343844 336494 347747 340800 339621 336990 336404 336977 335034 343492 339384 338635 339933 335906 333351 341628 336102 342264 339919 353108 355426 361978 357842 360448 369737 364141 355518 ];
didBH1 = [596408 594663 598502 601077 600220 594185 598491 599985 596588 627838 599286 600496 618934 603165 603870 604899 622353 594155 600922 601265 600685 597154 590811 592570 643522 645802 611973 662279 643128 599223 ];

%Binomial Heap:
idiBmH1 = [620274 630293 647376 614823 619812 645327 620756 620080 641719 623107 618409 640914 616888 608263 647415 615084 628491 647966 618681 642481 645736 646407 606982 647954 628244 638331 649042 626180 645062 669173 ];
didBmH1 = [877221 913834 889542 842682 901117 904255 876943 917558 901680 846244 910961 911196 848978 922881 903314 873103 908484 916840 851100 914025 899805 845944 902417 911049 850668 930686 881862 847781 920286 894063 ];

%Fibonacci Heap:
idiFH1 = [4012835 4401612 4030620 4003485 4358420 4017940 3958639 4403745 4039947 4003693 4447356 4054594 3986800 4362551 4285999 4270867 4558772 4316347 4025485 4374726 4028345 3976688 4377794 4332463 3963124 4417002 4328558 3991934 4398462 4289342 ];
didFH1 = [5108739 5454246 5171657 5068358 5452817 5166758 5105791 5237086 5155653 5097847 5484246 5179185 5136648 5612780 5176570 5442121 5587655 5550612 5115487 5500417 5209734 5100936 5634794 5240311 5088881 5631396 5579785 5119879 5598966 5565147 ];

%Van Emde Boas:
idiVEB1 = [2666528 2520563 2511028 2661079 2514710 2506070 2663121 2557992 2510333 2684948 2515864 2572939 2659807 2529181 2506065 2700153 2571907 2571400 2690925 2542107 2523712 2716252 2540867 2548290 2729521 2566767 2522238 2704100 2531844 2557934 ];
didVEB1 = [3235181 3197105 3179693 3268118 3168783 3204216 3239748 3218888 3188097 3209495 3183070 3323335 3231182 3162894 3199024 3241018 3175602 3184089 3275771 3232015 3254903 3285169 3184299 3218538 3247003 3239501 3216363 3243137 3185427 3211935 ];

%Splay Tree:
idiST1 = [676234 632072 636786 672342 660344 637241 672143 632290 629807 674983 643009 647763 678247 635709 635686 675156 627848 655123 668306 641655 634915 670926 631995 631848 676085 638818 638205 673797 639232 657178 ];
didST1 = [671756 685358 671046 679095 675303 679789 704451 693087 676547 676231 679778 700369 676983 702194 668705 666649 675007 688572 672158 667990 666910 674366 675675 692352 710155 669308 668613 678048 679498 673802 ];

%Test k=3 s=1:
%Binary Heap:
idiBH3 = [1185585 1171644 1147401 1162723 1172333 1153474 1166804 1177350 1149916 4253039 4228398 4218225 4255294 4207441 4191184 4211405 4180720 4181412 4510924 4453404 4426508 4260737 4219784 4211946 1891495 1903519 1873925 2117238 1903466 1901621 ];
didBH3 = [2048868 2253979 2055581 2050528 2259543 2073408 2053781 2265936 2047638 7505806 7467124 7464610 7618703 7587366 7523923 7557604 7491615 7470872 8291789 8258949 8245127 7499874 7470641 7484579 3082739 3354568 3328657 4001990 3394550 3397363 ];

%Binomial Heap:
idiBmH3 = [2690066 2968656 2586253 2185696 2277529 2250296 2280901 2375045 2192761 8122876 7827756 7719315 9087021 8757378 8738045 8189912 7873716 7813945 8060921 7777758 7706141 8110037 7800991 7721239 3912138 3816372 3774452 4007109 3897363 3872062 ];
didBmH3 = [3384233 3581623 3356845 2857757 3178437 2827709 2850482 3099909 2829969 10748165 10720122 10634253 11641966 11582693 11656589 10628074 10675546 10676112 10655720 10641462 10556016 10625347 10604009 10534628 4967214 4906610 4906051 5157939 5084775 5124710 ];

%Fibonacci Heap:
idiFH3 = [11482325 11752100 11810698 11506807 11755386 11769935 11526171 11801853 42675037 42065050 42948291 42850369 41974825 42746825 42590631 42320228 43150785 43063542 41903123 42872580 42849162 41933070 42875081 42743832 16381915 19106007 19096758 18902177 19068815 19070807 ];
didFH3 = [18690178 18896663 19081181 18617719 18990480 18983630 18664923 30447807 68583624 67589521 68489485 68328330 67729097 68189425 68127830 67834530 69238162 69160707 67353299 69006844 68853055 67229956 67540313 67498820 29872241 30407681 30408890 30087820 30363866 30337858 ];

%Van Emde Boas:
idiVEB3 = [9412320 9365624 9363988 9443934 9413027 9325764 33901648 33706840 33619888 34123396 34040593 33948009 33761811 33638821 33593584 33882272 33715700 33566277 34123947 34097287 33898561 33884859 15833712 14975336 15167254 15121120 15097290 15118352 15079181 15147260 ];
didVEB3 = [10681015 10628991 10644340 10640055 10639778 10636258 38418324 38326001 38314876 38449510 38323443 38268413 38340874 38242652 38170948 38428703 38312305 38269853 38552599 38363309 38346732 38457684 17036355 17029650 17180241 17136484 17120167 17047964 17267692 17023194 ];

%Splay Tree:
idiST3 = [2071770 1935989 1944895 2076725 1965883 1966013 7481477 7030630 7019128 7500675 7068370 7086622 7472160 7056524 7013857 7480509 7098163 7054082 7498786 7109063 7003824 3303627 3102267 3127127 3305511 3121651 3141581 3319695 2475561 1932862 ];
didST3 = [1962283 1969629 1986299 1972175 1996114 1965727 7234641 7178691 7133423 7136009 7140979 7098519 7137953 7181497 7166939 7141701 7154266 7131689 7141711 7101716 7121726 3153151 3196026 3118753 3138542 3162198 3149585 3171335 1957595 1969767 ];


%Test k=7 s=1:
%Binary Heap:
idiBH7 = [3419266 3140734 3142221 2837211 2805390 2955773 3070859 2792505 2907606 3144218 2789973 3053156 3093475 2798259 3047527 10260080 10182899 10156153 11219953 11167055 11124504 10322937 10179597 10233212 11181095 11069167 11040043 10745550 10631185 10621273 ];
didBH7 = [5902381 6355684 5881547 5132528 5871265 5147759 5155743 5605358 5177073 5098610 5351585 5105612 5104051 5323918 5099998 18601279 18543544 18514738 21278087 21281078 21233655 18518778 18541083 18546185 20706666 20641494 20922040 19787603 19764876 19719459 ];

%Binomial Heap:
idiBmH7 = [6055948 5837097 5830374 6044925 5857165 5830652 6193354 5956708 5902251 6409300 6190554 6185365 6099107 5897761 5869479 24726437 23947933 23920014 22276960 21502019 21429826 22290947 21465332 21519348 22432001 21822526 21677141 22254661 21404743 22233341 ];
didBmH7 = [7620529 7586375 7586385 7596880 7621421 7599502 7712864 7754879 7729536 8066467 8068106 8084285 7792991 7766533 7780080 31838211 31928720 31836211 28091158 28087735 28082548 27858205 27925061 27846073 28110421 28032320 28051357 28630765 28236382 28133424 ];

%Fibonacci Heap:
idiFH7 = [27833005 28366167 28408696 27840169 28407712 28411948 28328650 28857867 28716255 28086838 28653752 28648732 27717261 28479219 102762630 100890827 103037152 102705550 100400766 102222916 102318223 100888347 102576398 102518299 100489328 101760714 102220005 100375152 101633786 28085893 ];
didFH7 = [44592439 44891908 44992112 44589533 44939021 44948113 44904229 45089007 45145834 44933179 44954407 44915313 44437277 59624109 162912237 161048193 164110027 163432527 160738485 162250697 162233794 161907790 162860455 163862651 161086009 162542725 162671461 161564272 105211931 45125087 ];

%Van Emde Boas:
idiVEB7 = [24932959 24889880 24869292 24937927 25048170 25044369 24937286 24905842 24900917 25206298 25159061 25151587 90769096 91162544 90740104 91626003 91390840 91673146 91128652 90767278 90837432 90520217 90182857 90268181 90869860 90566181 90694904 25079875 25026956 25014580 ];
didVEB7 = [26373250 26339882 26353529 31283725 26744470 26684657 26331581 26382047 26340823 27458530 27445929 27437135 96687471 96659061 96437123 96690973 96143197 96361877 95895816 95923769 96192252 96020709 95933301 96549582 95845953 96142294 95870133 26382038 26369688 26382435 ];

%Splay Tree:
idiST7 = [4909666 4546748 4556855 4934201 4564928 4593830 4903799 4545202 4555804 4898737 4567948 4555040 17913500 16615007 16688971 17823362 16687553 16587404 17918752 16611394 16648133 18073438 16631962 16569164 17806664 16600364 16577468 4942036 4572073 4572186 ];
didST7 = [4211514 4237918 4230435 4250784 4242106 4246021 4228697 4244219 4234148 4225969 4259858 4225714 15351414 15417939 15379627 15351412 15408383 15440356 15419323 15468744 15507452 15479850 15501148 15427106 15383111 15461238 15713299 4220031 4251715 4232397 ];

n = 2^11;
divisor = n*log2(n);

k = [1 3 7];
%para tabla
idikABB = [mean(idiABB1) mean(idiABB3) mean(idiABB7)]
idikABBA = [mean(idiABBA1) mean(idiABBA3) mean(idiABBA7)]
idikAVL = [mean(idiAVL1) mean(idiAVL3) mean(idiAVL7)]
idikVEB = [mean(idiVEB1) mean(idiVEB3) mean(idiVEB7)]
idikST = [mean(idiST1) mean(idiST3) mean(idiST7)]
idikHT = [mean(idiHT1) mean(idiHT3) mean(idiHT7)]

didkABB = [mean(didABB1) mean(didABB3) mean(didABB7)]
didkABBA = [mean(didABBA1) mean(didABBA3) mean(didABBA7)]
didkAVL = [mean(didAVL1) mean(didAVL3) mean(didAVL7)]
didkVEB = [mean(didVEB1) mean(didVEB3) mean(didVEB7)]
didkST = [mean(didST1) mean(didST3) mean(didST7)]
didkHT = [mean(didHT1) mean(didHT3) mean(didHT7)]


%para graficar
idikABB = [mean(idiABB1) mean(idiABB3) mean(idiABB7)]/divisor;
idikABBA = [mean(idiABBA1) mean(idiABBA3) mean(idiABBA7)]/divisor;
idikAVL = [mean(idiAVL1) mean(idiAVL3) mean(idiAVL7)]/divisor;
idikVEB = [mean(idiVEB1) mean(idiVEB3) mean(idiVEB7)]/divisor;
idikST = [mean(idiST1) mean(idiST3) mean(idiST7)]/divisor;
idikHT = [mean(idiHT1) mean(idiHT3) mean(idiHT7)]/divisor;

didkABB = [mean(didABB1) mean(didABB3) mean(didABB7)]/divisor;
didkABBA = [mean(didABBA1) mean(didABBA3) mean(didABBA7)]/divisor;
didkAVL = [mean(didAVL1) mean(didAVL3) mean(didAVL7)]/divisor;
didkVEB = [mean(didVEB1) mean(didVEB3) mean(didVEB7)]/divisor;
didkST = [mean(didST1) mean(didST3) mean(didST7)]/divisor;
didkHT = [mean(didHT1) mean(didHT3) mean(didHT7)]/divisor;

clf
subplot(2,2,1)

plot(k,idikBH,'r-x','LineWidth',2);
hold on
plot(k,idikBmH,'b-+','LineWidth',2);
title("k v/s tiempo : elementos ordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ns]");
%axis([1,7,0,0.002])
hold on
plot(k,idikFH,'m-*','LineWidth',2);
hold on
plot(k,idikVEB,'g-o','LineWidth',2);
hold on
plot(k,idikST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Fibonacci Heap','Van Emde Boas','Splay Tree');
hold on

subplot(2,2,2)

plot(k,idikBH,'r-x','LineWidth',2);
hold on
plot(k,didkBmH,'b-+','LineWidth',2);
hold on
plot(k,didkFH,'m-*','LineWidth',2);
title("k v/s tiempo : elementos ordenados - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ns]");
%axis([1,7,0,0.008])
hold on
plot(k,didkVEB,'g-o','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Fibonacci Heap','Van Emde Boas','Splay Tree');
hold on


subplot(2,2,3)

plot(k,idikBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos ordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ns]");
hold on
plot(k,idikBmH,'b-+','LineWidth',2);
hold on
plot(k,idikST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold on

subplot(2,2,4)

plot(k,didkBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos ordenados - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ns]");
hold on
plot(k,didkBmH,'b-+','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold off

return