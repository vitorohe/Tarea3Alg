function[] = mediaBigks0

%Test k=1 s=0:
%Binary Heap:
idiBH1 = [210 209 209 210 210 209 350 349 349 216 216 215 ];
didBH1 = [365 366 365 365 366 365 614 610 610 375 375 375 ];

%Binomial Heap:
idiBmH1 = [199 734 188 696 303 223 267 696 ];
didBmH1 = [2009 1815 1741 2091 1250 926 1963 2149 ];

%Fibonacci Heap:
idiFH1 = [1441 1991 1643 1989 1970 2853 1287 1260 ];
didFH1 = [4941 4446 4726 5503 5948 5114 6964 7012 ];

%Van Emde Boas:
idiVEB1 = [3720 3256 2993 5397 3721 3904 4328 3829 ];
didVEB1 = [14578 15054 14567 14466 14762 15506 15139 15727 ];

%Splay Tree:
idiST1 = [902 1086 901 1150 1357 1086 1380 1119 ];
didST1 = [373 376 373 516 434 375 519 377 ];


%Test k=3 s=0:
%Binary Heap:
idiBH3 = [702 1466 702 690 1090 759 694 1980 1038 702 1967 1079 ];
didBH3 = [2814 1659 1914 1274 3773 1274 1401 2330 1401 1305 2264 1302 ];

%Binomial Heap:
idiBmH3 = [1715 761 672 739 634 736 629 735 ];
didBmH3 = [4124 5711 6055 4854 5694 3484 5718 3494 ];

%Fibonacci Heap:
idiFH3 = [7050 6528 5104 5778 6304 5681 5871 5260 ];
didFH3 = [20867 21943 19194 19639 18823 19123 18492 19158 ];

%Van Emde Boas:
idiVEB3 = [11518 10903 10952 11904 10697 9584 10858 9586 ];
didVEB3 = [38474 38363 37453 35676 36589 37325 35269 33758 ];

%Splay Tree:
idiST3 = [6005 4016 5654 4015 4791 4004 4618 4013 ];
didST3 = [1336 1340 1335 1337 1407 1338 1334 1337 ];

%Test k=7 s=0:
%Binary Heap:
idiBH7 = [1649 1640 1655 1637 1634 1632 1639 1735 1756 1762 1801 1842 ];
didBH7 = [6261 6281 5904 6231 5843 5836 6211 5736 5719 5746 5699 5660 ];

%Binomial Heap:
idiBmH7 = [1592 1833 1586 1831 1751 1836 1817 1923 ];
didBmH7 = [12557 12695 12633 12780 12483 12718 12482 12683 ];

%Fibonacci Heap:
idiFH7 = [16368 14424 15625 15769 16452 15812 16357 15750 ];
didFH7 = [49979 49909 48671 48982 48812 49648 48635 49353 ];

%Van Emde Boas:
idiVEB7 = [22518 21466 22527 23280 23291 20710 23285 22531 ];
didVEB7 = [76956 74792 74763 74159 78255 77522 75252 77164 ];

%Splay Tree:
idiST7 = [9268 10910 9597 12201 11817 10913 9351 10916 ];
didST7 = [3562 3564 3561 3563 3563 3567 3568 3568 ];



n = 2^19;
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
title("k v/s tiempo : elementos aleatorios - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
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
title("k v/s tiempo : elementos aleatorios - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
hold on
plot(k,didkVEB,'g-o','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Fibonacci Heap','Van Emde Boas','Splay Tree');
hold on


subplot(2,2,3)

plot(k,idikBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos aleatorios - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.008])
hold on
plot(k,idikBmH,'b-+','LineWidth',2);
hold on
plot(k,idikST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold on

subplot(2,2,4)

plot(k,didkBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos aleatorios - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.008])
hold on
plot(k,didkBmH,'b-+','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold off



return