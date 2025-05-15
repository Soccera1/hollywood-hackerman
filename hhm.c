#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define BOLD  "\x1B[1m"

void d(int ms) {
    usleep(ms * 1000);
}

void pf(const char *s, int cd) {
    for (int i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
        fflush(stdout);
        d(cd);
    }
    putchar('\n');
}

void p_bar(int p, int w, const char *l) {
    printf("%s%s: [", KYEL, l);
    int c = (p * w) / 100;
    for (int i = 0; i < w; i++) {
        if (i < c) printf("#");
        else printf("-");
    }
    printf("] %d%%%s\r", p, KNRM);
    fflush(stdout);
    if (p == 100) printf("\n");
}

char* r_hex(int len) {
    char* h = malloc(len + 1);
    if (!h) exit(1);
    char set[] = "0123456789ABCDEF";
    for (int i = 0; i < len; i++) h[i] = set[rand() % 16];
    h[len] = '\0';
    return h;
}

char* r_ip_addr() {
    static char ip[16];
    sprintf(ip, "%d.%d.%d.%d", rand() % 254 + 1, rand() % 255, rand() % 255, rand() % 254 + 1);
    return ip;
}

void rs_data(int lines) {
    printf("%s", KBLU);
    for (int i = 0; i < lines; i++) {
        char* h1 = r_hex(8); char* h2 = r_hex(8);
        char* h3 = r_hex(8); char* h4 = r_hex(8);
        printf("0x%s%04X: %s %s %s %s  |", KMAG, i * 16, h1, h2, h3, h4);
        for(int j=0; j<16; ++j) {
            char rc = (rand() % (126 - 32 + 1)) + 32;
            if (rc == '%' || rc == '\\') rc = '.';
            putchar(rc);
        }
        printf("|\n");
        free(h1); free(h2); free(h3); free(h4);
        d(15 + rand()%25);
        if (i % 20 == 0) fflush(stdout);
    }
    fflush(stdout);
    printf("%s", KNRM);
}


void init_stage() {
    system("clear");
    pf(BOLD KCYN "SYNCING WITH GLOBAL DARKNET RELAY NETWORK...", 30);
    d(500);
    pf(BOLD KGRN "H.A.W.K EYE TERMINAL v6.6.6 ONLINE", 25);
    d(300);
    pf(KGRN "NEURAL UPLINK ESTABLISHED. ENCRYPTION LAYER ACTIVE.", 20);
    d(300);
    pf(KGRN "QUANTUM FLUX PROCESSORS ENGAGED.", 20);
    d(500);
    for (int i = 0; i <= 100; i+= (rand() % 7 + 1)) {
        p_bar(i > 100 ? 100 : i, 50, "Loading Attack Modules");
        d(60 + rand()%40);
    }
    printf("\n");
    pf(BOLD KGRN "SYSTEMS OPERATIONAL. AWAITING TARGET COORDINATES.", 25);
    d(1000);
}

void target_acq_stage(char *target_ip_out) {
    pf(BOLD KYEL "\nINPUT TARGET IDENTIFIER (DNS/IP) OR [auto] FOR RANDOM:", 15);
    printf(BOLD KCYN "TARGET> ");
    fflush(stdout);
    d(800 + rand()%500);
    printf("%s\n", KNRM);

    char* f_ip = r_ip_addr();
    strcpy(target_ip_out, f_ip);
    pf(KCYN "AUTO-TARGETING INITIATED. SELECTING HIGH-VALUE ASSET...", 20);
    d(1500);

    pf(BOLD KCYN "\nINITIATING GLOBAL IP SWEEP FOR TARGET SIGNATURE...", 20);
    for (int i = 0; i <= 100; i+= (rand() % 4 + 1)) {
        p_bar(i > 100 ? 100 : i, 50, "Scanning Quadrant Gamma-7");
        if (i % 8 == 0 && i < 95) {
            printf(KNRM "\n%s  Pinging %s...", KYEL, r_ip_addr());
            fflush(stdout);
        }
        d(120 + rand()%80);
    }
    printf("\n");
    pf(BOLD KGRN "TARGET ACQUIRED AND LOCKED:", 20);
    char* f_host = r_hex(10);
    printf(BOLD KRED "    IP ADDRESS: %s\n", target_ip_out);
    printf(BOLD KRED "    EST. HOSTNAME: %s.corp.mil.gov\n", f_host);
    printf(BOLD KRED "    GEOLOCATION: UNDISCLOSED (SECURE FACILITY)\n" KNRM);
    free(f_host);
    d(2500);
}

void vuln_scan_stage() {
    pf(BOLD KCYN "\nCOMMENCING DEEP PENETRATION VULNERABILITY AUDIT...", 20);
    const char* v_types[] = {
        "CVE-2077-X0A1: HyperDimensional Array Overflow",
        "NSA-ANT-CATALOG: 'GODSURGE' Kernel Implant Vector",
        "FSB-REDCELL-TOOL: 'ZEROGRAVITY' Polymorphic Rootkit",
        "MSS-DRAGONFLY-OPS: 'SILENTSHADOW' Firmware Exploit",
        "PLA-UNIT61398-APT: 'GHOSTNET' Zero-Day RCE",
        "MI6-GREENWHISPER: Quantum Cryptography Bypass",
        "CSIS-AURORA-GOLD: AI-Powered Social Engineering Vector"
    };
    int num_v = sizeof(v_types) / sizeof(char*);

    for (int i = 0; i <= 100; i += (rand() % 12 + 4)) {
        p_bar(i > 100 ? 100 : i, 50, "Scanning Services & Open Ports");
        if (i % 15 == 0 && i < 95 ) {
            char* port_scan_hex = r_hex(rand()%3+4);
            printf(KNRM "\n%s  Probing Port %d (%s)... %sVULNERABLE %s(Severity: CRITICAL)%s",
                   KYEL, (rand()%40000)+1024, port_scan_hex, KRED, BOLD, KNRM KYEL);
            free(port_scan_hex);
            fflush(stdout);
        }
        d(250 + rand()%150);
    }
    printf("\n");

    pf(BOLD KRED "CRITICAL VULNERABILITIES IDENTIFIED:", 20);
    for (int i = 0; i < 4 + rand() % 2; i++) {
        printf(KRED "  -> %s\n", v_types[rand() % num_v]);
        d(400);
    }
    d(1500);
}

void exploit_stage() {
    char msg_buf[512];
    pf(BOLD KCYN "\nSELECTING OPTIMAL EXPLOIT CHAIN FROM ARSENAL...", 20);
    d(1500);
    pf(BOLD KYEL "EXPLOIT SELECTED: 'CHIMERA_HYDRA_V7' MULTI-VECTOR ATTACK", 20);
    d(1000);
    pf(BOLD KCYN "COMPILING ADAPTIVE PAYLOAD ON-THE-FLY...", 20);
    for (int i = 0; i <= 100; i += (rand() % 10 + 5)) {
        p_bar(i > 100 ? 100 : i, 50, "Generating Polymorphic Shellcode");
        if (i % 12 == 0 && i < 95) {
            char* r1 = r_hex(4); char* r2 = r_hex(4);
            printf(KNRM "\n%s   Using Encoder: x64/xor_dynamic_key, Key: 0x%s, Iter: %d, Mutation: %s",
                   KYEL, r1, rand()%20+10, r2);
            free(r1); free(r2);
            fflush(stdout);
        }
        d(180 + rand()%120);
    }
    printf("\n");
    pf(KCYN "  SHELLCODE ASSEMBLY (ENCRYPTED VIEW):", 15);
    rs_data(10);

    pf(BOLD KCYN "INITIATING EXPLOIT SEQUENCE...", 20);
    d(500);
    pf(KBLU "  [*] Targeting memory address 0xDEADBEEF...", 15);
    d(800);
    for(int k=0; k<4; ++k) {
        char* h1 = r_hex(8); char* h2 = r_hex(16);
        printf("%s      [+] Phase %d: Sending payload fragment %s (%d bytes). Hash: %s\n", KCYN, k+1, h1, rand()%1024+256, h2);
        free(h1); free(h2);
        d(400 + rand()%200);
    }
    pf(KBLU "  [*] Crafting ROP chain to bypass NX/ASLR...", 15);
    d(800);
    char* g1=r_hex(12); char* g2=r_hex(12); char* g3=r_hex(12);
    printf("%s      Gadget Alpha: pop rax; ret; at 0x%s\n", KCYN, g1); d(200);
    printf("%s      Gadget Beta:  mov [rdi], rsi; ret; at 0x%s\n", KCYN, g2); d(200);
    printf("%s      Gadget Gamma: syscall; ret; at 0x%s\n", KCYN, g3); d(200);
    free(g1); free(g2); free(g3);
    char* sh1 = r_hex(8); char* sh2 = r_hex(8);
    snprintf(msg_buf, sizeof(msg_buf), KBLU "  [*] Shellcode [0x%s - 0x%s] successfully injected into process %d.", sh1, sh2, rand()%5000+1000);
    pf(msg_buf, 15);
    free(sh1); free(sh2);
    d(1000);

    for (int i = 0; i <= 100; i += (rand() % 7 + 3)) {
        p_bar(i > 100 ? 100 : i, 50, "Executing Remote Code");
        d(220 + rand()%130);
    }
    printf("\n");
    pf(BOLD KGRN "EXPLOIT SUCCESSFUL! STABILIZING REVERSE SHELL...", 30);
    d(1500);
}

void bypass_sec_stage() {
    pf(BOLD KCYN "\nANALYZING TARGET DEFENSIVE POSTURE...", 20);
    d(1000);
    pf(KYEL "  [!] Firewall Detected: 'FORTRESS_OMEGA_MKII' (Adaptive AI Core)", 20);
    d(500);
    pf(KYEL "  [!] IDS/IPS Active: 'ARGUS_PANOPTES_V10' (Behavioral Analysis)", 20);
    d(500);
    pf(KYEL "  [!] AV Signature Scan: 'CERBERUS_GUARD' (Heuristic Engine)", 20);
    d(1000);

    pf(BOLD KCYN "DEPLOYING STEALTH AND EVASION SUBROUTINES...", 20);
    pf(KYEL "  [!] Target network employing deep packet inspection!", 15);
    d(700);
    pf(KBLU "  [*] Activating 'SPECTRAL_CLOAK' traffic fragmentation engine...", 15);
    for (int i = 0; i <= 100; i += (rand() % 22 + 8)) {
        p_bar(i > 100 ? 100 : i, 45, "Fragmenting Traffic");
        d(280 + rand()%120);
    }
    printf("\n");
    pf(KGRN "  [+] Traffic signature successfully obfuscated.", 15);
    d(700);

    pf(KYEL "  [!] AI-driven anomaly detection: 'GUARDIAN_ANGEL_AI' is active.", 15);
    d(700);
    pf(KBLU "  [*] Injecting adversarial noise pattern 'WHITE_NOISE_GENERATOR'...", 15);
    for (int i = 0; i <= 100; i += (rand() % 22 + 8)) {
        p_bar(i > 100 ? 100 : i, 45, "Confusing AI Detection");
        d(280 + rand()%120);
    }
    printf("\n");
    pf(KGRN "  [+] AI Anomaly detection temporarily blinded.", 15);
    d(700);
    
    pf(KBLU "  [*] Rerouting C2 traffic through multi-hop encrypted proxy chain...", 15);
    for(int k=0;k<5;k++){
        char *tor_hex = r_hex(6);
        printf("%s      Hop %d: %s (TOR Exit Node %s)\n", KCYN, k+1, r_ip_addr(), tor_hex);
        free(tor_hex);
        d(300 + rand()%200);
    }
    pf(KGRN "  [+] Anonymized C2 channel established.", 15);
    d(700);

    pf(BOLD KGRN "ALL DEFENSES BYPASSED. COMMAND CHANNEL SECURED.", 30);
    d(1000);
}

void gain_access_stage() {
    char msg_buf[512];
    pf(BOLD KCYN "\nATTEMPTING SYSTEM COMPROMISE AND PRIVILEGE ESCALATION...", 20);
    d(1000);
    pf(KYEL "  [*] Initiating credential harvesting: Targeting SAM/Shadow files...", 20);
    for (int i = 0; i < 30; i++) {
        char* u_attempt = r_hex(rand()%4+4);
        char* p_attempt = r_hex(rand()%8+8);
        char* err_hex = r_hex(8);
        printf(KRED "    Login: %s / Pass: %s ... AUTH FAILED (0x%s)\n", u_attempt, p_attempt, err_hex);
        free(u_attempt); free(p_attempt); free(err_hex);
        d(40 + rand()%40);
        if (i == 25 + (rand()%4)) {
             char* cracked_pass = r_hex(10);
             printf(KGRN "    Login: administrator / Pass: %s ... AUTH SUCCESSFUL!\n", cracked_pass);
             free(cracked_pass);
             break;
        }
    }
    d(500);
    pf(KGRN "  [+] Domain Administrator credentials acquired!", 20);
    d(1000);

    pf(BOLD KCYN "ESCALATING TO SYSTEM/ROOT PRIVILEGES...", 20);
    const char* priv_esc_v[] = {
        "Kernel Exploit 'DIRTY_PIPE_EXTENDED'", "SUID Binary Abuse 'PKEXEC_RELOADED'",
        "LD_PRELOAD Hijacking", "Cron Job Tampering via Symlink Attack",
        "Unquoted Service Path Exploitation", "Docker Socket Exposure"
    };
    snprintf(msg_buf, sizeof(msg_buf), KBLU "  [*] Attempting: %s", priv_esc_v[rand() % (sizeof(priv_esc_v)/sizeof(char*))]);
    pf(msg_buf, 20);
    for (int i = 0; i <= 100; i += (rand() % 12 + 6)) {
        p_bar(i > 100 ? 100 : i, 50, "Escalating Privileges");
        d(180 + rand()%120);
    }
    printf("\n");
    pf(BOLD KGRN "PRIVILEGE ESCALATION SUCCESSFUL! ACHIVED UID=0 (ROOT) ACCESS.", 30);
    char *root_host = r_hex(12);
    printf(KMAG BOLD "  root@%s:~# %s\n", root_host, KNRM);
    free(root_host);
    d(2500);
}

void data_exfil_stage() {
    char msg_buf[512];
    pf(BOLD KCYN "\nSCANNING FOR HIGH-VALUE DATA ASSETS ON TARGET NETWORK...", 20);
    d(1000);
    const char* data_f[] = {
        "/mnt/encrypted_archive/PROJECT_ZEUS_BLUEPRINTS.tar.gz.aes",
        "//FILESERVER01/CONFIDENTIAL/CLIENT_DATABASE_FULL.bak.7z",
        "/opt/R&D/PROPRIETARY_ALGORITHMS_SRC.zip",
        "/home/sysadmin/credentials/MASTER_PASSWORD_LIST.gpg",
        "/var/backups/daily/FINANCIAL_RECORDS_FY2077.db.enc"
    };
    pf(KYEL "  Potential Targets Found:", 20);
    for(int i=0; i<3+rand()%2; ++i) {
        printf(KYEL "    -> %s (Size: %d TB)\n", data_f[rand() % (sizeof(data_f)/sizeof(char*))], rand()%10+1);
        d(350);
    }
    d(1000);

    pf(BOLD KCYN "INITIATING COVERT DATA EXFILTRATION VIA 'WORMHOLE' PROTOCOL...", 20);
    pf(KBLU "  [*] Encrypting data stream with AES-GCM-1024 (Quantum Resistant)...", 15);
    d(1000);
    for (int i = 0; i <= 100; i += (rand() % 6 + 1)) {
        p_bar(i > 100 ? 100 : i, 50, "Exfiltrating Data");
        if (i % 20 == 0 && i < 95) {
            char *block_hex = r_hex(10);
            printf(KNRM "\n%s   Transmitting encrypted block %s... ACK_OK", KBLU, block_hex);
            free(block_hex);
            fflush(stdout);
        }
        d(280 + rand()%170);
    }
    printf("\n");
    pf(KCYN "  ENCRYPTED DATA STREAM (SAMPLE):", 15);
    rs_data(20);
    snprintf(msg_buf, sizeof(msg_buf), BOLD KGRN "DATA EXFILTRATION COMPLETE. %d PETABYTES SECURELY TRANSFERRED.", rand()%8+2);
    pf(msg_buf, 20);
    d(1500);
}

void payload_delivery_stage() {
    char msg_buf[512];
    pf(BOLD KCYN "\nDEPLOYING PERSISTENCE AGENT 'HYDRA_REBORN'...", 20);
    d(1000);
    const char* p_names[] = {
        "systemd-watchdogd", "kernel_update_svc.elf", "network_monitor.bin", "auditd_ext.so"
    };
    char* p_name = (char*)p_names[rand() % (sizeof(p_names)/sizeof(char*))];
    snprintf(msg_buf, sizeof(msg_buf), KYEL "  Payload: /usr/sbin/%s (Stealth Mode)", p_name);
    pf(msg_buf, 20);
    d(500);
    pf(BOLD KCYN "UPLOADING AND INTEGRATING PAYLOAD INTO SYSTEM CORE...", 20);
    for (int i = 0; i <= 100; i += (rand() % 9 + 3)) {
        p_bar(i > 100 ? 100 : i, 50, "Injecting Persistence Agent");
        d(180 + rand()%120);
    }
    printf("\n");
    snprintf(msg_buf, sizeof(msg_buf), KBLU "  [*] Executing: /usr/sbin/%s --daemon --hide --encrypt-c2", p_name);
    pf(msg_buf, 20);
    d(1000);
    snprintf(msg_buf, sizeof(msg_buf), KBLU "  [*] Registering as critical system service, PID: %d", rand()%100+10);
    pf(msg_buf, 20);
    d(500);
    pf(BOLD KGRN "PERSISTENCE ESTABLISHED. AGENT ACTIVE AND CLOAKED.", 30);
    d(1500);
}

void cover_tracks_stage() {
    pf(BOLD KCYN "\nACTIVATING ANTI-FORENSIC MEASURES 'GHOST PROTOCOL'...", 20);
    d(1000);
    const char* l_files[] = {
        "/var/log/secure", "/var/log/messages", "/var/log/kern.log",
        "/root/.bash_history", "/tmp/*", "/var/run/utmp", "/var/log/lastlog",
        "/var/log/audit/audit.log"
    };
    pf(KYEL "  Sanitizing critical system logs:", 20);
    for (int i = 0; i < 5; i++) {
        printf(KBLU "    [+] Securely wiping %s ... ", l_files[rand() % (sizeof(l_files)/sizeof(char*))]);
        fflush(stdout);
        d(600 + rand()%400);
        printf("%sDONE%s\n", KGRN, KBLU);
    }
    d(500);

    pf(KYEL "  [*] Modifying file timestamps (timestomping) across critical directories...", 20);
    d(1500);
    pf(KBLU "  [*] Overwriting free disk space with random data (Gutmann method)...", 20);
    for (int i = 0; i <= 100; i += (rand() % 12 + 8)) {
        p_bar(i > 100 ? 100 : i, 50, "Scrubbing Disk Sectors");
        d(250 + rand()%250);
    }
    printf("\n");
    pf(BOLD KGRN "ALL TRACES OBLITERATED. SYSTEM INTEGRITY APPEARS INTACT.", 30);
    d(1500);
}

void final_stage() {
    pf(BOLD KCYN "\nDISENGAGING FROM TARGET INFRASTRUCTURE...", 20);
    d(1000);
    pf(BOLD KGRN "ENCRYPTED C2 TUNNEL COLLAPSED.", 20);
    d(500);
    pf(BOLD KGRN "OPERATION 'MIDNIGHT_VIPER' CONCLUDED WITH MAXIMUM SUCCESS.", 40);
    d(2000);
    printf("%s\n", KNRM);
    printf(BOLD KGRN "\n\n"
"  ██╗  ██╗ █████╗  ██████╗██████╗ ██╗   ██╗███████╗████████╗\n"
"  ██║  ██║██╔══██╗██╔════╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝\n"
"  ███████║███████║██║     ██████╔╝██║   ██║█████╗     ██║   \n"
"  ██╔══██║██╔══██║██║     ██╔══██╗██║   ██║██╔══╝     ██║   \n"
"  ██║  ██║██║  ██║╚██████╗██║  ██║╚██████╔╝███████╗   ██║   \n"
"  ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝   ╚═╝   \n" KNRM);

    d(1500);
    pf(BOLD KYEL "\nSESSION TERMINATED. LOGGING OFF H.A.W.K EYE TERMINAL...", 30);
    d(2000);
    system("clear");
}

int main() {
    srand(time(NULL));
    char target_ip[100];

    init_stage();
    target_acq_stage(target_ip);
    vuln_scan_stage();
    exploit_stage();
    bypass_sec_stage();
    gain_access_stage();

    int op_choice = rand() % 3;
    if (op_choice == 0) {
        data_exfil_stage();
    } else if (op_choice == 1) {
        payload_delivery_stage();
    } else {
        data_exfil_stage();
        d(1000);
        payload_delivery_stage();
    }

    cover_tracks_stage();
    final_stage();

    return 0;
}
