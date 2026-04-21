# Pacman

## O que acontece dentro de Vector2MoveTowards

```cpp
enemyPos = Vector2MoveTowards(enemyPos, playerPos, enemySpeed);
```

- subtração de vetores para saber a direção
- pitagoras para saber a distancia
- normalização para que o personagem não teletransporte até o alvo

```cpp
Vector2 direction = {playerPos.x - enemyPos.x, playerPos.y - enemyPos.y};
float length =
  std::sqrtf((std::pow(direction.x, 2.0) + std::pow(direction.y, 2.0)));
if (length > 0) {
  direction.x = direction.x / length;
  direction.y = direction.y / length;
}
enemyPos.x += direction.x * enemySpeed;
enemyPos.y += direction.y * enemySpeed;
```
