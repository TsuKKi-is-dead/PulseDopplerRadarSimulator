import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

plt.style.use('dark_background')

class RadarVisualizer:
    def __init__(self):
        self.fig, (self.ax1, self.ax2) = plt.subplots(1, 2, figsize=(16, 8))
        self.fig.suptitle('PULSE-DOPPLER RADAR SYSTEM\nENEMY AIRCRAFT TRACKING', 
                         fontsize=18, fontweight='bold', color='cyan')
        
        self.targets = [
            {"name": "Enemy Fighter-1", "range": 15.0, "vel": 250, "color": "red"},
            {"name": "Enemy Bomber",    "range": 28.0, "vel": -180, "color": "orange"},
            {"name": "Enemy Recon",     "range": 42.0, "vel": 80,   "color": "magenta"}
        ]
        self.frame = 0
        
    def update(self, frame):
        self.frame = frame
        self.ax1.clear()
        self.ax2.clear()
        
        # === LEFT: Range-Doppler Map ===
        self.ax1.set_title('Range - Doppler Map', fontsize=14, color='white')
        self.ax1.set_xlabel('Range (km)')
        self.ax1.set_ylabel('Velocity (m/s)')
        
        x = np.linspace(0, 50, 250)
        y = np.linspace(-500, 500, 250)
        X, Y = np.meshgrid(x, y)
        Z = np.zeros_like(X, dtype=float)
        
        for t in self.targets:
            Z += np.exp(-((X - t["range"])**2) / 40) * np.exp(-((Y - t["vel"])**2) / 7000)
        
        Z += np.random.normal(0, 0.5, Z.shape)
        
        im = self.ax1.imshow(Z, extent=[0, 50, -500, 500], aspect='auto', 
                           cmap='jet', alpha=0.92)
        plt.colorbar(im, ax=self.ax1, label='Signal Intensity')
        
        for t in self.targets:
            self.ax1.scatter(t["range"], t["vel"], c=t["color"], s=220, 
                           marker='^', edgecolors='yellow', linewidth=2.5)
        
        # === RIGHT: Very Slow Tracking ===
        self.ax2.set_title('Real-time Enemy Aircraft Tracking', fontsize=14, color='white')
        self.ax2.set_xlabel('Range (km)')
        self.ax2.set_ylabel('Velocity (m/s)')
        self.ax2.grid(True, alpha=0.3)
        self.ax2.set_xlim(0, 55)
        self.ax2.set_ylim(-450, 450)
        
        for i, t in enumerate(self.targets):
            # Very slow and smooth movement
            curr_r = t["range"] + np.sin(self.frame / 25.0 + i*2) * 1.5
            curr_v = t["vel"] + np.cos(self.frame / 30.0 + i) * 6
            
            self.ax2.scatter(curr_r, curr_v, c=t["color"], s=350, marker='^', label=t["name"])
            
            self.ax2.annotate(f"{t['name']}\n{curr_r:.1f} km\n{curr_v:.0f} m/s", 
                            (curr_r + 1.5, curr_v), color='white', fontsize=10.5)
        
        if self.frame % 10 == 0:  # Show legend less frequently
            self.ax2.legend(loc='upper right')
        
        self.fig.tight_layout()

def main():
    viz = RadarVisualizer()
    # VERY SLOW ANIMATION
    ani = animation.FuncAnimation(viz.fig, viz.update, 
                                frames=200, 
                                interval=1200,   # 1.2 seconds per frame → very slow
                                repeat=True)
    
    print("🚀 Very Slow & Beautiful Radar Visualization Started")
    print("→ Movement is now much slower and calmer")
    print("→ Close the window to stop")
    plt.show()

if __name__ == "__main__":
    main()
