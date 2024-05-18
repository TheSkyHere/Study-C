#include <stdio.h>
#include <time.h>

void convertTimestampToAbsoluteTime(time_t timestamp) {
    struct tm *timeinfo;
    timeinfo = localtime(&timestamp);
    
    printf("Absolute Time: %s", asctime(timeinfo));
}

int main() {
    time_t timestamp = 1616428800; // 示例时间戳，表示2021年3月23日00:00:00的UNIX时间戳
    
    convertTimestampToAbsoluteTime(timestamp);
    
    return 0;
}
