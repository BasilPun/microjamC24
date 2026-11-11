#include "mj/mj_title_backdrop_1.h"

#include "bn_rect_window.h"
#include "bn_regular_bg_items_mj3_title_back.h"

namespace mj
{

    title_backdrop_1::title_backdrop_1() : _bg_1(bn::regular_bg_items::mj3_title_back.create_bg(0, 0)),
                                           _camera(bn::camera_ptr::create(0, 0))
    {
        bn::rect_window internal_window = bn::rect_window::internal();
        internal_window.set_boundaries(-80, -120, 80, 120);
        internal_window.set_camera(_camera);

        _bg_1.set_camera(_camera);
    }

    title_backdrop_1::~title_backdrop_1()
    {
        bn::rect_window::internal().restore();
    }

    bn::optional<bn::fixed> title_backdrop_1::update()
    {
        bn::optional<bn::fixed> fade_intensity;
        ++_counter;

        if (_counter == frames_per_bg_update)
        {
            bn::fixed camera_x = _camera.x() + 1;
            _counter = 0;
            _camera.set_x(camera_x);
        }

        return fade_intensity;
    }

}
