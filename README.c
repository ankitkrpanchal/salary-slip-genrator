#include <stdio.h>
#include <string.h>

// ============================================================
//   SALARY SLIP GENERATOR
//   Subject      : Programming With C
//   Submitted By : Ankit Kumar
//   Roll No.     : 212131825003
//   Branch       : Computer Science & Engineering (2nd Sem)
//   College      : Rajeev College of Professional Education,
//                  Sitamarhi
//   Teacher      : Vijay Kumar
// ============================================================

struct Employee {
    char name[50];
    char emp_id[20];
    char designation[50];
    char department[50];
    char doj[20];
    char bank_acc[20];
    char company[50];
    char month[20];
};

struct Salary {
    float basic, hra, da, ta, medical, other_earn;
    float pf, esi, tds, prof_tax, loan, other_ded;
};

void numberToWords(float amount) {
    int num = (int)amount;
    char *ones[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
                    "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
                    "Seventeen","Eighteen","Nineteen"};
    char *tens_arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    if (num == 0) { printf("Zero Rupees Only"); return; }
    if (num >= 100000) { printf("%s Lakh ", ones[num/100000]); num %= 100000; }
    if (num >= 1000) {
        if (num/1000 >= 20) printf("%s Thousand ", tens_arr[(num/1000)/10]);
        else printf("%s Thousand ", ones[num/1000]);
        num %= 1000;
    }
    if (num >= 100) { printf("%s Hundred ", ones[num/100]); num %= 100; }
    if (num >= 20)  { printf("%s ", tens_arr[num/10]); num %= 10; }
    if (num > 0)    { printf("%s ", ones[num]); }
    printf("Rupees Only");
}

void drawLine(int len)       { int i; for(i=0;i<len;i++) printf("-"); printf("\n"); }
void drawDoubleLine(int len) { int i; for(i=0;i<len;i++) printf("="); printf("\n"); }

void inputEmployee(struct Employee *e) {
    printf("\n  Enter Company Name      : ");
    fgets(e->company, 50, stdin);
    e->company[strcspn(e->company, "\n")] = '\0';

    printf("  Enter Salary Month/Year : ");
    fgets(e->month, 20, stdin);
    e->month[strcspn(e->month, "\n")] = '\0';

    printf("\n  Enter Employee Name     : ");
    fgets(e->name, 50, stdin);
    e->name[strcspn(e->name, "\n")] = '\0';

    printf("  Enter Employee ID       : ");
    fgets(e->emp_id, 20, stdin);
    e->emp_id[strcspn(e->emp_id, "\n")] = '\0';

    printf("  Enter Designation       : ");
    fgets(e->designation, 50, stdin);
    e->designation[strcspn(e->designation, "\n")] = '\0';

    printf("  Enter Department        : ");
    fgets(e->department, 50, stdin);
    e->department[strcspn(e->department, "\n")] = '\0';

    printf("  Enter Date of Joining   : ");
    fgets(e->doj, 20, stdin);
    e->doj[strcspn(e->doj, "\n")] = '\0';

    printf("  Enter Bank Account No.  : ");
    fgets(e->bank_acc, 20, stdin);
    e->bank_acc[strcspn(e->bank_acc, "\n")] = '\0';
}

void inputSalary(struct Salary *s) {
    printf("\n  -------- EARNINGS --------\n");
    printf("  Basic Salary         : Rs. "); scanf("%f", &s->basic);
    printf("  HRA                  : Rs. "); scanf("%f", &s->hra);
    printf("  DA (Dearness Allow.) : Rs. "); scanf("%f", &s->da);
    printf("  TA (Travel Allow.)   : Rs. "); scanf("%f", &s->ta);
    printf("  Medical Allowance    : Rs. "); scanf("%f", &s->medical);
    printf("  Other Allowance      : Rs. "); scanf("%f", &s->other_earn);

    printf("\n  ------- DEDUCTIONS -------\n");
    printf("  Provident Fund (PF)  : Rs. "); scanf("%f", &s->pf);
    printf("  ESI                  : Rs. "); scanf("%f", &s->esi);
    printf("  TDS / Income Tax     : Rs. "); scanf("%f", &s->tds);
    printf("  Professional Tax     : Rs. "); scanf("%f", &s->prof_tax);
    printf("  Loan / Advance       : Rs. "); scanf("%f", &s->loan);
    printf("  Other Deductions     : Rs. "); scanf("%f", &s->other_ded);
    while (getchar() != '\n');
}

float calcEarnings(struct Salary s) {
    return s.basic + s.hra + s.da + s.ta + s.medical + s.other_earn;
}

float calcDeductions(struct Salary s) {
    return s.pf + s.esi + s.tds + s.prof_tax + s.loan + s.other_ded;
}

void printStudentDetails() {
    drawDoubleLine(65);
    printf("                    PROJECT DETAILS\n");
    drawLine(65);
    printf("  Subject      : Programming With C\n");
    printf("  Submitted By : Ankit Kumar\n");
    printf("  Roll No.     : 212131825003\n");
    printf("  Branch       : Computer Science & Engineering (2nd Sem)\n");
    printf("  College      : Rajeev College of Professional Education,\n");
    printf("                 Sitamarhi\n");
    printf("  Teacher      : Vijay Kumar\n");
    drawDoubleLine(65);
}

void printSlip(struct Employee e, struct Salary s) {
    float totalEarn = calcEarnings(s);
    float totalDed  = calcDeductions(s);
    float netSalary = totalEarn - totalDed;

    printf("\n\n");
    drawDoubleLine(65);
    printf("                     SALARY SLIP\n");
    drawDoubleLine(65);
    printf("  Company  : %-30s  Month : %s\n", e.company, e.month);
    drawLine(65);
    printf("  Name         : %-25s  Emp ID   : %s\n", e.name, e.emp_id);
    printf("  Designation  : %-25s  Dept     : %s\n", e.designation, e.department);
    printf("  Date of Join : %-25s  Bank A/C : %s\n", e.doj, e.bank_acc);
    drawLine(65);

    printf("  %-30s  %-30s\n", "EARNINGS", "DEDUCTIONS");
    drawLine(65);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "Basic Salary",   s.basic,      "Provident Fund",   s.pf);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "HRA",            s.hra,        "ESI",              s.esi);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "DA",             s.da,         "TDS/Income Tax",   s.tds);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "TA",             s.ta,         "Professional Tax", s.prof_tax);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "Medical Allow.", s.medical,    "Loan/Advance",     s.loan);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "Other Allow.",   s.other_earn, "Other Deductions", s.other_ded);
    drawLine(65);
    printf("  %-24s %7.2f  %-20s %7.2f\n", "TOTAL EARNINGS", totalEarn, "TOTAL DEDUCTIONS", totalDed);
    drawDoubleLine(65);

    printf("  NET SALARY (Take-Home) : Rs. %.2f\n", netSalary);
    printf("  In Words : ");
    numberToWords(netSalary);
    printf("\n");
    drawLine(65);
    printf("  Employee Signature : _______________   Authorized Signatory : _______________\n");
    drawDoubleLine(65);

    printf("\n");
    printStudentDetails();
}

void saveToFile(struct Employee e, struct Salary s) {
    FILE *fp;
    char filename[80];
    float totalEarn = calcEarnings(s);
    float totalDed  = calcDeductions(s);
    float netSalary = totalEarn - totalDed;

    snprintf(filename, sizeof(filename), "%s_%s.txt", e.emp_id, e.month);
    fp = fopen(filename, "w");
    if (fp == NULL) { printf("\n  Error: Could not save file!\n"); return; }

    fprintf(fp, "=================================================================\n");
    fprintf(fp, "                       SALARY SLIP\n");
    fprintf(fp, "=================================================================\n");
    fprintf(fp, "  Company  : %-30s  Month : %s\n", e.company, e.month);
    fprintf(fp, "-----------------------------------------------------------------\n");
    fprintf(fp, "  Name         : %-25s  Emp ID   : %s\n", e.name, e.emp_id);
    fprintf(fp, "  Designation  : %-25s  Dept     : %s\n", e.designation, e.department);
    fprintf(fp, "  Date of Join : %-25s  Bank A/C : %s\n", e.doj, e.bank_acc);
    fprintf(fp, "-----------------------------------------------------------------\n");
    fprintf(fp, "  %-30s  %-30s\n", "EARNINGS", "DEDUCTIONS");
    fprintf(fp, "-----------------------------------------------------------------\n");
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "Basic Salary",   s.basic,      "Provident Fund",   s.pf);
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "HRA",            s.hra,        "ESI",              s.esi);
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "DA",             s.da,         "TDS/Income Tax",   s.tds);
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "TA",             s.ta,         "Professional Tax", s.prof_tax);
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "Medical Allow.", s.medical,    "Loan/Advance",     s.loan);
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "Other Allow.",   s.other_earn, "Other Deductions", s.other_ded);
    fprintf(fp, "-----------------------------------------------------------------\n");
    fprintf(fp, "  %-24s %7.2f  %-20s %7.2f\n", "TOTAL EARNINGS", totalEarn, "TOTAL DEDUCTIONS", totalDed);
    fprintf(fp, "=================================================================\n");
    fprintf(fp, "  NET SALARY (Take-Home) : Rs. %.2f\n", netSalary);
    fprintf(fp, "=================================================================\n");
    fprintf(fp, "  Employee Signature : _______________   Authorized Signatory : _______________\n");
    fprintf(fp, "=================================================================\n");
    fprintf(fp, "\n");
    fprintf(fp, "=================================================================\n");
    fprintf(fp, "                    PROJECT DETAILS\n");
    fprintf(fp, "-----------------------------------------------------------------\n");
    fprintf(fp, "  Subject      : Programming With C\n");
    fprintf(fp, "  Submitted By : Ankit Kumar\n");
    fprintf(fp, "  Roll No.     : 212131825003\n");
    fprintf(fp, "  Branch       : Computer Science & Engineering (2nd Sem)\n");
    fprintf(fp, "  College      : Rajeev College of Professional Education,\n");
    fprintf(fp, "                 Sitamarhi\n");
    fprintf(fp, "  Teacher      : Vijay Kumar\n");
    fprintf(fp, "=================================================================\n");

    fclose(fp);
    printf("\n  Slip saved to file: %s\n", filename);
}

// ============================================================
//   MAIN FUNCTION
// ============================================================
int main() {
    struct Employee emp;
    struct Salary   sal;
    int choice;

    printf("\n");
    drawDoubleLine(65);
    printf("         SALARY SLIP GENERATOR - Programming With C\n");
    drawLine(65);
    printf("  Submitted By : Ankit Kumar\n");
    printf("  Roll No.     : 212131825003\n");
    printf("  Branch       : CSE (2nd Semester)\n");
    printf("  College      : Rajeev College of Professional Education,\n");
    printf("                 Sitamarhi\n");
    printf("  Teacher      : Vijay Kumar\n");
    drawDoubleLine(65);

    inputEmployee(&emp);
    inputSalary(&sal);
    printSlip(emp, sal);

    printf("\n  Do you want to save the slip to a text file?\n");
    printf("  1. Yes    2. No\n");
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        saveToFile(emp, sal);
    }

    printf("\n  Thank you! Program ended.\n\n");
    return 0;
}
