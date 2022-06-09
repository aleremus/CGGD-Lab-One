#include "raytracer_renderer.h"

#include "utils/resource_utils.h"

#include <iostream>


void cg::renderer::ray_tracing_renderer::init()
{

	model = std::make_shared<cg::world::model>();
	model->load_obj(settings->model_path);

	camera = std::make_shared<cg::world::camera>();
	camera->set_height(static_cast<float>(settings->height));
	camera->set_width(static_cast<float>(settings->width));
	camera->set_position(
			float3{
					settings->camera_position[0],
					settings->camera_position[1],
					settings->camera_position[2]
			}
	);
	camera->set_phi(settings->camera_phi);
	camera->set_theta(settings->camera_theta);
	camera->set_angle_of_view(settings->camera_angle_of_view);
	camera->set_z_near(settings->camera_z_near);
	camera->set_z_far(settings->camera_z_far);

	render_target = std::make_shared<cg::resource<cg::unsigned_color>>(
			settings->width,settings->height
	);

	raytracer = std::make_shared<cg::renderer::raytracer<cg::vertex,cg::unsigned_color>>();

	raytracer->set_render_target(render_target);
	raytracer->set_viewport(settings->width, settings->height);
	raytracer->set_vertex_buffers(model->get_vertex_buffers());
	raytracer->set_index_buffers(model->get_index_buffers());
	// TODO: Lab 2.03. Add light information to lights array of ray_tracing_renderer
	// TODO: Lab 2.04. Initialize `shadow_raytracer` in `ray_tracing_renderer`
}

void cg::renderer::ray_tracing_renderer::destroy() {}

void cg::renderer::ray_tracing_renderer::update() {}

void cg::renderer::ray_tracing_renderer::render()
{
	// TODO: Lab 2.01. Implement miss_shader, image clearing, calling ray_generation, and saving in ray_tracing_renderer class
	// TODO: Lab 2.02. Add closest_hit_shader to raytracer class to return diffuse color
	// TODO: Lab 2.03. Adjust closest_hit_shader of raytracer to implement Lambertian shading model
	// TODO: Lab 2.04. Define any_hit_shader and miss_shader for shadow_raytracer
	// TODO: Lab 2.04. Adjust closest_hit_shader of raytracer to cast shadows rays and to ignore occluded lights
	// TODO: Lab 2.05. Adjust ray_tracing_renderer class to build the acceleration structure
}