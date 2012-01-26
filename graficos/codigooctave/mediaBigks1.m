function[] = mediaBigks1

%Test k=1 s=1:
%Binary Heap:
idiBH1 = [186 186 185 140 140 140 140 140 509 139 139 139 ];
didBH1 = [379 379 1316 271 272 271 271 862 987 269 270 269 ];

%Binomial Heap:
idiBmH1 = [576 282 479 628 286 284 289 283 ];
didBmH1 = [410 416 923 513 411 415 411 418 ];

%Fibonacci Heap:
idiFH1 = [2850 2828 3233 3968 2649 3111 3629 3736 ];
didFH1 = [4455 5261 3389 2814 4343 3728 3608 2917 ];

%Van Emde Boas:
idiVEB1 = [3189 1770 2809 1770 1855 1844 2615 3200 ];
didVEB1 = [10952 12231 10485 9741 13042 12344 11661 10472 ];

%Splay Tree:
idiST1 = [180 182 200 199 288 182 286 282 ];
didST1 = [186 192 212 216 286 193 291 527 ];

%Test k=3 s=1:
%Binary Heap:
idiBH3 = [461 458 458 461 1041 740 458 465 788 488 1766 746 ];
didBH3 = [854 854 1357 864 2719 1150 852 3091 1280 1420 1851 901 ];

%Binomial Heap:
idiBmH3 = [1024 644 636 1545 641 1035 643 1546 ];
didBmH3 = [1150 927 907 2521 1220 1448 1079 2108 ];

%Fibonacci Heap:
idiFH3 = [7805 7372 7518 7546 7410 7662 7513 7549 ];
didFH3 = [13194 11837 11658 13493 12096 13117 11658 13098 ];

%Van Emde Boas:
idiVEB3 = [7496 7498 8579 7402 7274 6752 8143 7421 ];
didVEB3 = [33903 36431 35573 33076 32680 33112 33046 31939 ];

%Splay Tree:
idiST3 = [544 543 1876 846 866 622 855 1266 ];
didST3 = [543 556 1019 653 849 555 1591 860 ];

%Test k=7 s=1:
%Binary Heap:
idiBH7 = [2946 1088 1295 1653 1087 1149 1626 1671 1139 1278 1119 1606 ];
didBH7 = [2554 4502 2322 2064 5011 2102 2067 3327 2468 4543 2086 3358 ];

%Binomial Heap:
idiBmH7 = [2471 2140 2067 2644 2254 2584 2896 2062 ];
didBmH7 = [4347 5456 4188 3256 4769 4137 3916 4509 ];

%Fibonacci Heap:
idiFH7 = [17290 17187 17228 17269 16379 16262 17095 16380 ];
didFH7 = [30823 30789 29096 27005 29670 28447 27869 27091 ];

%Van Emde Boas:
idiVEB7 = [18839 17365 18598 17493 18208 17494 17342 17341 ];
didVEB7 = [75547 75261 75326 74603 74545 74322 72534 71424 ];

%Splay Tree:
idiST7 = [1514 1270 3227 1269 1287 1979 1286 1674 ];
didST7 = [1175 1198 1689 1236 1250 1852 1172 1853 ];


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
title("k v/s tiempo : elementos ordenados - Secuencia (idi)");
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
title("k v/s tiempo : elementos ordenados - Secuencia (did)");
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
title("k v/s tiempo : elementos ordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.00045])
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
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.00045])
hold on
plot(k,didkBmH,'b-+','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold off
return