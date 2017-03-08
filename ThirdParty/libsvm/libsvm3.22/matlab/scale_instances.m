function scaled = scale_instances(instance_matrix)
    for i = 1:size(instance_matrix, 2)
        lo = min(instance_matrix(:, i));
        hi = max(instance_matrix(:, i));
        range = hi - lo;
        instance_matrix(:, i) = 2 * ((instance_matrix(:, i) - lo) / range) - 1;
    end
    scaled = instance_matrix;
end