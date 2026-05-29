import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

plt.style.use('dark_background')

class RadarVisualizer:
    def __init__(self):
        self.fig, (self.ax1, self.ax2) = plt.subplots(1, 2, figsize=(16, 8))
        self.fig.suptitle('PULSE-DOPPLER RADAR SYSTEM\nENEMY AIRCRAFT TRACKING', 
                         fontsize=18, fontweight='bold', color='cyan')
        self.frame = 0
        self.targets = []
        
    def update(self, frame):
        self.frame = frame
        self.ax1.clear()
        self.ax2.clear()
        
        self.ax1.set_title('Range - Doppler Map', fontsize=14, color='white')
        self.ax1.set_xlabel('Range (km)')
        self.ax1.set_ylabel('Velocity (m/s)')
        
        x = np.linspace(0, 50, 250)
        y = np.linspace(-500, 500, 250)
        X, Y = np.meshgrid(x, y)
        Z = np.zeros_like(X, dtype=float)
        
        colors = ['red', 'orange', 'magenta', 'lime', 'cyan']
        
        for i, t in enumerate(self.targets):
            Z += np.exp(-((X - t["range"])**2) / 45) * np.exp(-((Y - t["vel"])**2) / 8000)
            color = colors[i % len(colors)]
            self.ax1.scatter(t["range"], t["vel"], c=color, s=200, marker='^', edgecolors='yellow')
        
        Z += np.random.normal(0, 0.6, Z.shape)
        im = self.ax1.imshow(Z, extent=[0, 50, -500, 500], aspect='auto', cmap='jet', alpha=0.9)
        plt.colorbar(im, ax=self.ax1, label='Signal Intensity')
        
        self.ax2.set_title('Real-time Tracking', fontsize=14, color='white')
        self.ax2.set_xlabel('Range (km)')
        self.ax2.set_ylabel('Velocity (m/s)')
        self.ax2.grid(True, alpha=0.3)
        self.ax2.set_xlim(0, 55)
        self.ax2.set_ylim(-450, 450)
        
        for i, t in enumerate(self.targets):
            curr_r = t["range"] + np.sin(self.frame / 25.0 + i) * 1.5
            curr_v = t["vel"] + np.cos(self.frame / 30.0 + i) * 7
            color = colors[i % len(colors)]
            
            self.ax2.scatter(curr_r, curr_v, c=color, s=300, marker='^', label=t["name"])
            self.ax2.annotate(f"{t['name']}\n{curr_r:.1f}km\n{curr_v:.0f}m/s", 
                            (curr_r+1, curr_v), color='white', fontsize=10)
        
        if self.frame < 8:
            self.ax2.legend(loc='upper right')
        self.fig.tight_layout()

def main():
    viz = RadarVisualizer()
    
    num_targets = random.randint(2, 5)
    for i in range(num_targets):
        viz.targets.append({
            "name": f"Enemy {i+1}",
            "range": random.uniform(8, 48),
            "vel": random.uniform(-380, 380)
        })
    
    print(f"🚀 Visualizing {num_targets} Enemy Aircraft")
    ani = animation.FuncAnimation(viz.fig, viz.update, frames=150, interval=1050, repeat=True)
    plt.show()

if __name__ == "__main__":
    main()
