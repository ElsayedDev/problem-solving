#!/usr/bin/python



infinity = float("inf")
graph = {}
costs = {}
parents = {}
processed = []

parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None

graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2

costs["start"] = {}
costs["start"]["a"] = 6
costs["start"]["b"] = 2

def find_lowest_cost_node():
    lowest_cost = float("inf")
    lowest_cost_node= None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost =cost
            lowest_cost_node = node 
    return lowest_cost_node
    

node = find_lowest_cost_node()
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if costs[n] > new_cost:
            costs[n] = new_cost
            parents[n] =node
    processed.append(node)
    node = find_lowest_cost_node()