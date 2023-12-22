#include "mainwindow.h"
#include "Material.h"
#define COUNTM 4

double calculationOfMultiPanelGlass(double f) {
    double multiPanelGlass = 2.0 + (0.2 * f);
    return multiPanelGlass;
}

double calculationOfGlass(double f) {
    double glass = 23.0 + (0.3 * f);
    return glass;
}

double calculationOfConcrete(double f) {
    double concrete = 5.0 + (4.0 * f);
    return concrete;
}

double calculationOfWood(double f) {
    double wood = 4.85 + (0.12 * f);
    return wood;
}

double computeAttention(int materialType, double frequency) {
    if (materialType >= 0 &&  materialType < 4) {
        return arrayOfMaterial[materialType](frequency);
    } else {
        return 0.0;
    }
}
double (*arrayOfMaterial[4])(double) {
    calculationOfMultiPanelGlass,
    calculationOfGlass,
    calculationOfConcrete,
    calculationOfWood
};
Material material[COUNTM] = {
};
