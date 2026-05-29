import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Circle

plt.style.use('dark_background')

def main():
    fig = plt.figure(figsize=(16, 8))
    fig.suptitle('PULSE-DOPPLER RADAR SYSTEM\nEnemy Aircraft Tracking', 
                 fontsize=18, fontweight='bold', color='cyan')
    
    # Left: Range-Doppler Map
    ax1 = plt.subplot(1, 2, 1)
    ax1.set_title('Range - Doppler Map', fontsize=14, color='white')
    ax1.set_xlabel('Range (km)', fontsize=12)
    ax1.set_ylabel('Velocity (m/s)', fontsize=12)
    
    # Simulated Range-Doppler Heatmap
    range_bins = np.linspace(0, 50, 200)
    doppler_bins = np.linspace(-500, 500, 200)
    X, Y = np.meshgrid(range_bins, doppler_bins)
    Z = np.exp(-((X-15)**2)/50) + np.exp(-((X-28)**2)/60) + np.exp(-((X-42)**2)/70)
    Z += np.random.normal(0, 0.3, Z.shape)  # Add noise
    
    im = ax1.imshow(Z, extent=[0, 50, -500, 500], aspect='auto', cmap='jet', alpha=0.9)
    plt.colorbar(im, ax=ax1, label='Signal Intensity')
    
    # Mark Detected Targets
    ax1.scatter([15, 28, 42], [250, -180, 80], c='red', s=200, marker='^', 
                label='Detected Targets', edgecolors='yellow', linewidth=2)
    ax1.legend()
    
    # Right: Tracking Display
    ax2 = plt.subplot(1, 2, 2)
    ax2.set_title('Real-time Enemy Aircraft Tracking', fontsize=14, color='white')
    ax2.set_xlabel('Range (km)', fontsize=12)
    ax2.set_ylabel('Velocity (m/s)', fontsize=12)
    ax2.grid(True, alpha=0.3)
    
    # Plot Enemy Planes
    targets = [
        {"range": 15, "vel": 250, "id": 1, "name": "Enemy Fighter-1"},
        {"range": 28, "vel": -180, "id": 2, "name": "Enemy Bomber"},
        {"range": 42, "vel": 80, "id": 3, "name": "Enemy Recon"}
    ]
    
    colors = ['red', 'orange', 'magenta']
    
    for i, t in enumerate(targets):
        ax2.scatter(t["range"], t["vel"], c=colors[i], s=300, marker='^', 
                    label=f'Track {t["id"]}: {t["name"]}')
        ax2.annotate(f'Track {t["id"]}\n{t["range"]} km\n{t["vel"]} m/s', 
                     (t["range"]+0.5, t["vel"]), color='white', fontsize=10)
    
    ax2.legend(loc='upper right')
    ax2.set_xlim(0, 50)
    ax2.set_ylim(-400, 400)
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    print("Launching Radar Visualization...")
    main()
