import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec


data = pd.read_csv("out.txt", delimiter=",", header=None, index_col=0)

t, y, vy = data.T.values

gs = gridspec.GridSpec(2,1)
fig = plt.figure()

plt.axis("off")

# DISTANCE
dist_plot = fig.add_subplot(gs[0])
dist_plot.grid()
dist_plot.plot(t, y)
fig.gca().set_xlim(0, max(t))
dist_plot.title.set_text("Distance")

# SPEED
speed_plot = fig.add_subplot(gs[1], sharex=dist_plot)
speed_plot.grid()
speed_plot.plot(t, vy)
speed_plot.title.set_text("Speed")

fig.tight_layout(pad=2)

plt.savefig("plots/plot.png")
plt.show()
