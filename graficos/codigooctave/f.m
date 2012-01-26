
fkABB= [mean(didABB1) mean(didABB3) mean(didABB7)]/divisor;
fkABBA = [mean(didABBA1) mean(didABBA3) mean(didABBA7)]/divisor;
fkAVL = [mean(didAVL1) mean(didAVL3) mean(didAVL7)]/divisor;
fkVEB = [mean(didVEB1) mean(didVEB3) mean(didVEB7)]/divisor;
fkST = [mean(didST1) mean(didST3) mean(didST7)]/divisor;

subplot(2,2,3)

plot(k,idikABB,'r-x','LineWidth',2);
title("k v/s tiempo : elementos semiordenados - Secuencia (idi)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.0011])
hold on
plot(k,idikABBA,'b-+','LineWidth',2);
hold on
plot(k,idikST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold on

subplot(2,2,4)

plot(k,didkABB,'r-x','LineWidth',2);
title("k v/s tiempo : elementos semiordenados - Secuencia (did)");
xlabel("k");
ylabel("t / n * log (n ) [ms]");
axis([1,7,0,0.0011])
hold on
plot(k,didkABBA,'b-+','LineWidth',2);
hold on
plot(k,didkST,'k-@','LineWidth',2);
legend('Binary Heap','Binomial Heap','Splay Tree');
hold off
return