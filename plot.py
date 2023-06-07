import sys
import uproot
import numpy as np
import vector
import matplotlib.pyplot as plt
input_file = "pytree.root"
input = uproot.open(input_file)
events = input["Event"]
info = input["Info"]
gamma_gamma_ecm = info["eCMsubSave"].array()
fig, ax = plt.subplots()
fig.suptitle('Photon-Photon Center of Mass Energy')
ax.set_xlabel('$E_{CM}$ (GeV)')
ax.set_ylabel('Events per GeV')
ax.hist(gamma_gamma_ecm, bins=200, linewidth=0.5, edgecolor="white")
ax.set(xlim=(0, 200))
plt.show()
sig_gen = info["sigGen"].array()
fig, ax = plt.subplots()
fig.suptitle('Photon-Photon Cross Section')
ax.set_xlabel('$\sigma_{\gamma\gamma}$ (mb)')
ax.set_ylabel('Counts')
ax.hist(sig_gen, bins=200, linewidth=0.5, edgecolor="white")
ax.set(xlim=(2.5E-06, 3.5E-06))
plt.show()
mode = info["gammaModeEvent"].array()
fig, ax = plt.subplots()
fig.suptitle('Photon-Photon Scattering Mode')
ax.set_xlabel('$\gamma$-Mode')
ax.set_ylabel('Counts')
ax.hist(mode, bins=6, linewidth=0.5, edgecolor="white")
ax.set(xlim=(0, 6))
plt.show()
