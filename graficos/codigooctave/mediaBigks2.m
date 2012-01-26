function[] = mediaBigks2

%Test k=1 s=2:
%Binary Heap:
idiBH1 = [290 289 180 228 181 182 291 187 180 182 182 181 ];
didBH1 = [530 413 330 333 332 333 530 329 330 332 331 332 ];

%Binomial Heap:
idiBmH1 = [485 549 485 820 485 600 716 820 ];
didBmH1 = [1074 1101 1621 1666 1078 1663 2779 1360 ];

%Fibonacci Heap:
idiFH1 = [2527 3107 2531 2938 3332 3304 2529 3927 ];
didFH1 = [5666 4495 4472 5873 4457 5506 4764 5770 ];

%Van Emde Boas:
idiVEB1 = [3254 3254 2210 2733 2622 2072 2064 3063 ];
didVEB1 = [10454 10709 11230 10194 11526 11412 10183 11051 ];

%Splay Tree:
idiST1 = [1110 1207 1111 1209 907 834 734 833 ];
didST1 = [545 558 544 561 370 391 370 431 ];

%Test k=3 s=2:
%Binary Heap:
idiBH3 = [950 594 594 592 1103 704 1077 941 590 593 1864 592 ];
didBH3 = [1743 1128 1171 2447 1782 1118 2583 1429 1137 2233 1721 1122 ];

%Binomial Heap:
idiBmH3 = [2352 1763 2061 1762 2352 1758 3237 1757 ];
didBmH3 = [3657 4599 4691 3641 3734 3638 4291 3635 ];

%Fibonacci Heap:
idiFH3 = [8816 7870 8419 8439 8820 7838 8813 8858 ];
didFH3 = [17845 18704 18542 17262 18639 18024 16810 17125 ];

%Van Emde Boas:
idiVEB3 = [8557 8274 9450 8017 8998 8280 7707 7538 ];
didVEB3 = [33329 32963 32772 33049 32242 32237 31858 32078 ];

%Splay Tree:
idiST3 = [3839 3007 2747 3006 2590 2862 3835 3004 ];
didST3 = [1483 1316 1267 1317 1215 1255 1421 1314 ];

%Test k=7 s=2:
%Binary Heap:
idiBH7 = [2989 1978 1458 2094 2306 1538 1897 2294 3471 1918 2296 1660 ];
didBH7 = [2959 4220 4423 3490 3372 5401 3632 3207 3462 3613 3223 4519 ];

%Binomial Heap:
idiBmH7 = [6127 4563 4300 4548 4161 4538 6658 4543 ];
didBmH7 = [10049 10295 10013 10259 9960 10207 9964 10208 ];

%Fibonacci Heap:
idiFH7 = [20719 20463 20637 19207 20589 20919 19715 20845 ];
didFH7 = [43936 44010 45208 45998 44961 45390 44707 43686 ];

%Van Emde Boas:
idiVEB7 = [19082 18927 20059 19473 19445 18011 19913 19508 ];
didVEB7 = [76000 74825 75376 74077 75164 74507 75184 74862 ];

%Splay Tree:
idiST7 = [7006 7855 7000 7860 7021 7870 8122 7891 ];
didST7 = [3147 3248 3153 3253 3160 3261 3215 3320 ];



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
title("k v/s tiempo : elementos semiordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.008])
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
title("k v/s tiempo : elementos semiordenados - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.008])
hold on
plot(k,didkVEB,'g-o','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Fibonacci Heap','Van Emde Boas','Splay Tree');
hold on


subplot(2,2,3)

plot(k,idikBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos semiordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.0011])
hold on
plot(k,idikBmH,'b-+','LineWidth',2);
hold on
plot(k,idikST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold on

subplot(2,2,4)

plot(k,didkBH,'r-x','LineWidth',2);
title("k v/s tiempo : elementos semiordenados - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.0011])
hold on
plot(k,didkBmH,'b-+','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold off
return