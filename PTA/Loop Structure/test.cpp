#include <stdio.h>

int solve(int n) {
    int count = 0;
    //xyz大中小
    for(int x = 0; x <= n / 5; x++) {
        for(int y = 0; y <= n / 3; y++) {
            for(int z = 0; z <= n; z += 2) {
                //总数是否为n
                if(x + y + z == n) {
                    //总担数是否为n
                    if(5 * x + 3 * y + z / 2 == n) {
                        count++;
                    }
                }
            }
        }
    }
return count;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }

}