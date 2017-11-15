#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
// Headerfiles
#include <string>
#include <map>
#include <typeinfo>
#include <typeindex>
#include "GameObject.h"
#include "ComponentHeaders.h"
TEST_CASE("Vector3", "[vector3]" ) 
{
    Vector3 *v = new Vector3(1, 1, 1);
    Vector3 *v1 = new Vector3(2, 2, 2);
    SECTION("multipliers")
    {
        *v = (*v * 3);
        REQUIRE(*v == Vector3(3, 3, 3));
        *v = ((*v) * (*v1));
        REQUIRE(*v == Vector3(6, 6, 6));
    }
    *v = new Vector3(1, 1, 1);
    SECTION("additions")
    {
        *v += Vector3(0, 3, 0);
        REQUIRE(*v == Vector3(1,4,1));
    }
    *v = new Vector3(1, 1, 1);
    SECTION("subtractions")
    {
        *v -= Vector3(1, 1, 1);
        REQUIRE(*v == Vector3(0, 0, 0));
        *v -= Vector3(1000, 1000, 1000);
        REQUIRE(*v == Vector3(-1000, -1000, -1000));
    }
    *v = new Vector3(1, 1, 1);
    SECTION("matrix multiplications")
    {

    }
    *v = new Vector3(1, 1, 1);
    SECTION("magnitude")
    {
        Vector3 *vm2 = new Vector3(2,2,1);
        REQUIRE(v->magnitude() == sqrtf(3));
        REQUIRE(vm2->magnitude() == 3);
    }
}
TEST_CASE("GameObject", "[gameobject]")
{
    GameObject *go = new GameObject();
    SECTION("Components")
    {
        
        go->addComponent(new AccelerationComponent());
        go->addComponent(new VelocityComponent());
        AccelerationComponent *ac = new AccelerationComponent();
        VelocityComponent *vc = new VelocityComponent();
        // LIst 1
        std::map<std::string, Component *> *componentList = new std::map<std::string, Component*>();
        (*componentList)[typeid(*ac).name()] = ac;
        (*componentList)[typeid(*vc).name()] = vc;
        // List 2
        std::map<std::string, Component *> *componentList2 = new std::map<std::string, Component*>();
        (*componentList2)[typeid(*ac).name()] = ac;
        // REQUIRE(go->compareMaps(go->getComponentList(), *componentList) == true);
        REQUIRE(*(go->getComponent<AccelerationComponent *>()) == *ac);
        go->removeComponent<VelocityComponent *>();
        // REQUIRE(go->compareMaps(go->getComponentList(), *componentList2) == true);
        REQUIRE(go->hasComponent<AccelerationComponent *>() == true);
    }
}
TEST_CASE("Transform", "[transform]")
{
    Transform *t = new Transform();
    SECTION("Position") // is this not just transform?
    {
        REQUIRE(t->getPosition() == Vector3());
        t->setPosition(Vector3(25,0,56));
        REQUIRE(t->getPosition() == Vector3(25, 0, 56));
    }
    SECTION("Rotation")
    {
        REQUIRE(t->getRotation() == Vector3());
        t->setRotation(Vector3(0.25, 44, 180));
        REQUIRE(t->getRotation() == Vector3(0.25, 44, 180));
    }
    SECTION("Scale")
    {
        REQUIRE(t->getScale() == 1);
        t->setScale(t->getScale() * 15);
        REQUIRE(t->getScale() == 15);
    }
    t->adjustDirections(); //TODO: What does this do?

}