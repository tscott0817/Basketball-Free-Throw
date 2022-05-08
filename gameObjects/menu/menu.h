#ifndef M4OEP_GRAPHICS_TSCOTT5_MENU_H
#define M4OEP_GRAPHICS_TSCOTT5_MENU_H

#include "../primitives/rect.h"
#include "../prefabsSimple/prefabsSimple.h"
#include "../prefabsComplex/prefabsComplex.h"
#include <string>
#include <memory>
#include <vector>

/**
 * Creates menu display and adds functionality to buttons
 */
class Menu : public Rect {
private:
    std::string label;
    std::string labelTwo;
    std::string labelThree;
    std::string labelFour;
    std::string labelFive;
    std::vector<Rect> ui;
    std::vector<std::unique_ptr<PrefabsSimple>> simplePrefabs;
    std::vector<std::unique_ptr<PrefabsComplex>> complexPrefabs;
    std::vector<Rect> enviroMenu;
public:
    Menu();
    virtual void draw() const override;

    std::vector<Rect> getMenu() const;

    bool isOverlappingOne(int x, int y) const;
    bool isOverlappingTwo(int x, int y) const;
    bool isOverlappingThree(int x, int y) const;
    bool isOverlappingFour(int x, int y) const;

    void openMenu();
    void openEnviroMenu();
    void closeMenu();
    bool getCanOpen();
    void setCanOpen(bool open);
    void spawnSimpleObjects();
    void spawnComplexObjects();

    void drawObject(int x, int y, std::string objectName);
    void drawTree(int x, int y) const;
    void drawWindow(int x, int y) const;
    void drawComplexObjects() const;
    //void drawObjects();
    void moveSimpleObject(int x, int y);

    void hoverOne();
    void hoverTwo();
    void hoverThree();
    void hoverFour();

    void clickOne();
    void clickTwo();
    void clickThree();
    void clickFour();

    void release();
};

#endif //M4OEP_GRAPHICS_TSCOTT5_MENU_H
