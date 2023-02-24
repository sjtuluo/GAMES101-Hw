//
// Created by Göksu Güvendiren on 2019-05-14.
//

#include "Scene.hpp"


void Scene::buildBVH() {
    printf(" - Generating BVH...\n\n");
    this->bvh = new BVHAccel(objects, 1, BVHAccel::SplitMethod::NAIVE);
}

Intersection Scene::intersect(const Ray &ray) const
{
    return this->bvh->Intersect(ray);
}

void Scene::sampleLight(Intersection &pos, float &pdf) const
{
    float emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
        }
    }
    float p = get_random_float() * emit_area_sum;
    emit_area_sum = 0;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        if (objects[k]->hasEmit()){
            emit_area_sum += objects[k]->getArea();
            if (p <= emit_area_sum){
                objects[k]->Sample(pos, pdf);
                break;
            }
        }
    }
}

bool Scene::trace(
        const Ray &ray,
        const std::vector<Object*> &objects,
        float &tNear, uint32_t &index, Object **hitObject)
{
    *hitObject = nullptr;
    for (uint32_t k = 0; k < objects.size(); ++k) {
        float tNearK = kInfinity;
        uint32_t indexK;
        Vector2f uvK;
        if (objects[k]->intersect(ray, tNearK, indexK) && tNearK < tNear) {
            *hitObject = objects[k];
            tNear = tNearK;
            index = indexK;
        }
    }


    return (*hitObject != nullptr);
}

// Implementation of Path Tracing
Vector3f Scene::castRay(const Ray &ray, int depth) const
{
    // TO DO Implement Path Tracing Algorithm here
    //=========================================================
    Vector3f L_dir = { 0,0,0 };
    Vector3f L_indir = { 0,0,0 };

    // Whether intersection happens between ray and object
    Intersection inter_0 = this->intersect(ray);

    // No intersection 
    if (!inter_0.happened)
    {
        return Vector3f {};
    }
    
    // The ray hit the light source
    if (inter_0.m->hasEmission()) 
    {
        return inter_0.m->getEmission();
    } 

    // The ray hit other objects
    Intersection inter_1;
    float pdf_light = 0.0f;

    // Sampling the light
    sampleLight(inter_1, pdf_light);
    Vector3f wo = normalize(-ray.direction);
    Vector3f p = inter_0.coords;
    Vector3f N = inter_0.normal;

    // Get x, ws, NN, emit from inter
    Vector3f x = inter_1.coords;
    Vector3f ws = normalize(x - p);
    Vector3f NN = inter_1.normal;
    Vector3f emit = inter_1.emit;
    
    // Shoot a ray from p to x
    Ray ray_2(p, ws);
    
    // If the ray is not blocked in the middle
    if ((intersect(ray_2).coords - x).norm() <= EPSILON)
    {
        L_dir = emit * inter_0.m->eval(wo, ws, N) * dotProduct(ws, N) * dotProduct(-ws, NN) 
            / ((x - p).norm() * (x - p).norm()) / pdf_light;
    }
   
    // Test Russian Roulette with probability RussianRoulette
    if (get_random_float() <= RussianRoulette)
    {
        Vector3f wi = normalize(inter_0.m->sample(wo, N));
        // Trace a ray
        Ray ray_i(p, wi);
        Intersection inter_i = this->intersect(ray_i);
        // If ray r hit a non-emitting object at q
        if (inter_i.happened && !inter_i.m->hasEmission())
        {
            L_indir = castRay(ray_i, depth) * inter_0.m->eval(wi, wo, N) * dotProduct(wi, N)
                / (inter_0.m->pdf(wi, wo, N) * RussianRoulette);
        }
    }
    return L_dir + L_indir;
    //=========================================================
}