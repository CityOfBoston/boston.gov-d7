Custom styles can be added here.

Because we're creating a base/sub theme setup after getting really far
with a single theme, you'll likely come across a situation where you'll
need to move styles here from the base theme so you aren't fighting with
those styles in the hub's theme.

This will need to be handled in a case by case basis.

Currently the style.css file is commented out in the boston_public.info file
because we aren't loading any theme specific styles.

Use SMACSS. Mimic what's happening in the base theme. You'll possibly only
need to add component styles here, and even then, a subset of component styles,
like the ones that control color or typography.
