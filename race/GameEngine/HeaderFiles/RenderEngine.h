#pragma once
class RenderEngine {
public:
    void start();
    void update();
    RenderEngine();
    ~RenderEngine();
private:
    void loop();
};