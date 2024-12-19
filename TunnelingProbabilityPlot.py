import numpy as np
import matplotlib.pyplot as plt

# Constants
mass = 9.1e-31
e = 1.60217663e-19
U = 1 * e
hbar = 1.05457e-34

# Compute Te
Te = 0
L_values = np.linspace(1e-9, 10e-9, 1000)
E_values = np.linspace(0.1 * e, 1 * e, 1000)
L_mesh, E_mesh = np.meshgrid(L_values, E_values)

for L in L_values:
    for E in E_values:
        Te += 16 * (E / U) * (1 - (E / U)) * np.exp(-2 * L * np.sqrt(2 * mass * (U - E) / hbar**2))

print(f"Normal: {Te}")

# Compute the function to plot
Func = np.zeros(L_mesh.shape)
for i in range(L_mesh.shape[0]):
    for j in range(L_mesh.shape[1]):
        L = L_mesh[i, j]
        E = E_mesh[i, j]
        Func[i, j] = 16 * (E / U) * (1 - (E / U)) * np.exp(-2 * L * np.sqrt(2 * mass * (U - E) / hbar**2)) / Te

# Plotting
plt.figure(figsize=(10, 8))
contour = plt.contourf(L_mesh, E_mesh, Func, levels=20, cmap='viridis')
plt.colorbar(contour)

plt.xlabel('L (m)')
plt.ylabel('E (J)')
plt.title('Contour Plot of Function with Normalization')
plt.show()