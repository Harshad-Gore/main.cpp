import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Add nodes
G.add_nodes_from(["User Input", "Preprocessing", "Sentiment Analysis Model", "Output"])

# Add edges
G.add_edges_from([
    ("User Input", "Preprocessing"),
    ("Preprocessing", "Sentiment Analysis Model"),
    ("Sentiment Analysis Model", "Output")
])

# Layout and drawing configuration
pos = {
    "User Input": (0, 3),
    "Preprocessing": (0, 2),
    "Sentiment Analysis Model": (0, 1),
    "Output": (0, 0),
}

# Draw the flowchart
plt.figure(figsize=(4, 8))
nx.draw(G, pos, with_labels=True, arrows=True, node_size=3000, node_color="white", font_size=10, font_color="black", edge_color="black")
plt.show()