#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    printf("=======================================\n");
    printf("T-BOX C程序验证测试\n");
    printf("=======================================\n\n");
    
    // 获取并打印当前时间
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    printf("系统时间: %s", asctime(tm_info));
    
    // 打印程序参数
    printf("程序参数: %d 个\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("  参数[%d]: %s\n", i, argv[i]);
    }
    
    // 基本系统信息
    printf("\n=== 基础系统信息 ===\n");
    
    // CPU架构检测
    #if defined(__arm__)
        printf("CPU架构: ARM 32-bit\n");
    #elif defined(__aarch64__)
        printf("CPU架构: ARM 64-bit (AArch64)\n");
    #elif defined(__x86_64__)
        printf("CPU架构: x86-64\n");
    #elif defined(__i386__)
        printf("CPU架构: x86 32-bit\n");
    #else
        printf("CPU架构: 未知\n");
    #endif
    
    // 编译器信息
    #ifdef __GNUC__
        printf("编译器: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #endif
    
    // 简单的数学计算
    printf("\n=== 简单计算测试 ===\n");
    int a = 10, b = 20;
    int sum = a + b;
    int product = a * b;
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d * %d = %d\n", a, b, product);
    
    // 文件系统测试
    printf("\n=== 文件系统测试 ===\n");
    
    // 测试当前目录
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd))) {
        printf("当前工作目录: %s\n", cwd);
    } else {
        printf("无法获取当前目录\n");
    }
    
    // 内存测试
    printf("\n=== 内存测试 ===\n");
    printf("内存分配测试: ");
    int *ptr = malloc(100 * sizeof(int));
    if (ptr) {
        printf("成功分配 100 个整数\n");
        
        // 使用内存
        for (int i = 0; i < 100; i++) {
            ptr[i] = i * i;
        }
        
        // 验证
        printf("验证数据: ptr[10] = %d, ptr[20] = %d\n", ptr[10], ptr[20]);
        
        free(ptr);
        printf("内存释放成功\n");
    } else {
        printf("内存分配失败\n");
    }
    
    // 系统调用测试
    printf("\n=== 系统调用测试 ===\n");
    
    // 获取进程ID
    printf("进程ID: %d\n", getpid());
    printf("父进程ID: %d\n", getppid());
    
    // 获取用户ID
    printf("用户ID: %d\n", getuid());
    printf("有效用户ID: %d\n", geteuid());
    
    // 性能测试
    printf("\n=== 性能测试 ===\n");
    clock_t start = clock();
    
    // 执行一些计算
    volatile double result = 0;
    for (long i = 0; i < 1000000; i++) {
        result += i * 0.1;
    }
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计算 100万次耗时: %.6f 秒\n", cpu_time);
    
    // 环境变量测试
    printf("\n=== 环境变量测试 ===\n");
    char *path = getenv("PATH");
    if (path) {
        printf("PATH 变量长度: %zu 字符\n", strlen(path));
        // 只显示前100个字符避免过长
        char path_preview[101];
        strncpy(path_preview, path, 100);
        path_preview[100] = '\0';
        printf("PATH 预览: %s...\n", path_preview);
    } else {
        printf("PATH 环境变量未设置\n");
    }
    
    // 网络测试（简单版本）
    printf("\n=== 网络测试 ===\n");
    printf("主机名: ");
    fflush(stdout);
    system("hostname 2>/dev/null || echo '未知'");
    
    printf("\n=== 测试完成 ===\n");
    printf("所有基础测试已完成，程序将在5秒后退出\n");
    
    for (int i = 5; i > 0; i--) {
        printf("倒计时: %d 秒...\n", i);
        sleep(1);
    }
    
    return 0;
}