#include <gui/main_screen/MainView.hpp>

static int randomNumberBetween(int lowest, int highest);
static int randomNumberBetween(int lowest, int highest)
{
#ifdef SIMULATOR
    return lowest + (highest - lowest) * rand() / RAND_MAX;
#else
    uint32_t random = (touchgfx::HAL::getInstance()->getCPUCycles() * HAL::getInstance()->getCPUCycles());
    return lowest + (random % (highest - lowest));
#endif
}

MainView::MainView()
{

}

void MainView::setupScreen()
{
    // Place the graph on the screen
    graph.setXY(20, 20);

    // Set the outer dimensions and color of the graph
    graph.setup(440, 200, Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xAC));

    // Set the range for the x and y axis of the graph. That is
    // the max and min x/y value that can be displayed inside the
    // dimension of the graph.
    graph.setRange(0, 50, 0, 200);

    // Set the line width in pixels
    graph.setLineWidth(2);

    add(graph);
}

void MainView::tearDownScreen()
{
}

void MainView::handleTickEvent()
{
    // Number of ticks between inserting a point in the graph
    int interval = 5;

    tickCounter++;

    if (tickCounter % interval == 0)
    {
        // Insert a point in the graph.
        // The Y value is a random number in the y range of the graph.
        graph.addValue(tickCounter / interval, randomNumberBetween(graph.getRangeBottom(), graph.getRangeTop()));
    }

    if (tickCounter == 37 * interval)
    {
        // Change the range of the Y axis
        graph.setRange(0, 50, 0, 400);
        graph.invalidate();
    }

    if (tickCounter == 50 * interval)
    {
        // Reset the graph and start over
        graph.setRange(0, 50, 0, 200);
        graph.setLineWidth(2);
        graph.clear();
        graph.invalidate();

        tickCounter = 0;
    }
}

