function plot_mds(mds, label_vector)
    scatter3(mds(:, 1), mds(:, 2), mds(:, 3), 3, label_vector)
end