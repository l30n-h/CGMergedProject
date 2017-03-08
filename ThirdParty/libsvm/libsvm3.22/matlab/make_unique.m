function [unique_labels, unique_instances] = make_unique(labels, instances)
    [unique_instances, indices, ~] = unique(instances, 'rows');
    unique_labels = labels(indices);
end