#include "SpawnEnemies.h"

SpawnEnemies::SpawnEnemies(float ratio, float radius, Player *player) : timeToSpawnMax(ratio), radius(radius), player(player)
{
}

SpawnEnemies::~SpawnEnemies()
{
}

void SpawnEnemies::Update(float dt)
{
    timeToSpawn += dt;
    if (timeToSpawn >= timeToSpawnMax)
    {
        timeToSpawn = 0.0f;
        for (int i = 0; i < countOfEnemies; i++)
        {
            // quiero spawnearlos en una posicion aleatoria de un circulo al rededor del jugador
            //  Generar un ángulo aleatorio entre 0 y 2π
            float angle = GetRandomValue(0, 360) * DEG2RAD;

            // Generar una distancia aleatoria entre 0 y el radio máximo
            float distance = GetRandomValue(radius, 2 * radius);

            // Calcular la posición usando coordenadas polares
            Vector2 pos = {
                player->getWordPosition().x + distance * cos(angle),
                player->getWordPosition().y + distance * sin(angle)};
            // escribir en la consola
            std::cout << "Enemy spawned at: " << pos.x << ", " << pos.y << std::endl;
            enemies.push_back(new Enemy(idle, idle, pos, player));
        }
    }

    for (ICollisionWithBullet *enemy : enemies)
    {
        // neet to cast to ObjectInscreane
        static_cast<Enemy *>(enemy)->TickFrame(dt);
        static_cast<Enemy *>(enemy)->Render();
    }
}