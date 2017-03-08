function Y = compute_mds(instance_matrix)
    D = pdist(instance_matrix);
    Y = mdscale(D, 3, 'Start', 'random');
end